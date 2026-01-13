#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include "Grafo.h"

using namespace std;

static const string KEVIN = "KevinBacon";

bool resuelveCaso() {
    int numPeliculas;
    if (!(cin >> numPeliculas)) return false; // EOF

    unordered_map<string, int> idActor;
    idActor.reserve(200000);

    vector<pair<int, int>> actuaciones; // (actorId, peliculaId)
    actuaciones.reserve(200000);

    // Leemos pel�culas y montamos actuaciones actor-pel�cula
    for (int i = 0; i < numPeliculas; ++i) {
        string titulo;
        int numActores;
        cin >> titulo >> numActores;

        for (int j = 0; j < numActores; ++j) {
            string nombreActor;
            cin >> nombreActor;

            int actorId;
            auto it = idActor.find(nombreActor);
            if (it == idActor.end()) {
                actorId = (int)idActor.size();
                idActor.insert({ nombreActor, actorId });
            }
            else {
                actorId = it->second;
            }

            actuaciones.push_back({ actorId, i });
        }
    }

    // Total de vértices: actores + películas
    int totalActores = (int)idActor.size();
    int numVertices = totalActores + numPeliculas;
    Grafo grafo(numVertices);

    // Añadimos aristas actor <-> película
    for (auto const& actuacion : actuaciones) {
        int actorVertex = actuacion.first;
        int peliculaVertex = totalActores + actuacion.second;
        grafo.ponArista(actorVertex, peliculaVertex);
    }

    // Consultas
    int numConsultas;
    cin >> numConsultas;
    vector<string> consultas(numConsultas);
    for (int i = 0; i < numConsultas; ++i) cin >> consultas[i];

    // BFS desde Kevin Bacon (si existe)
    vector<int> distancias(numVertices, -1);
    queue<int> cola;

    auto itKevin = idActor.find(KEVIN);
    if (itKevin != idActor.end()) {
        int kevinVertex = itKevin->second;
        distancias[kevinVertex] = 0;
        cola.push(kevinVertex);

        while (!cola.empty()) {
            int verticeActual = cola.front(); 
            cola.pop();
            for (int vecino : grafo.ady(verticeActual)) {
                if (distancias[vecino] == -1) {
                    distancias[vecino] = distancias[verticeActual] + 1;
                    cola.push(vecino);
                }
            }
        }
    }

    // Responder consultas
    for (int i = 0; i < numConsultas; ++i) {
        string const& nombreConsulta = consultas[i];
        cout << nombreConsulta << " ";

        auto it = idActor.find(nombreConsulta);
        if (it == idActor.end()) {
            cout << "INF\n";
        }
        else {
            int actorVertex = it->second;
            if (distancias[actorVertex] == -1) 
                cout << "INF\n";
            else 
                cout << (distancias[actorVertex] / 2) << "\n"; // Grafo bipartito: actor-peli-actor = +2
        }
    }

    cout << "---\n";
    return true;
}

int main() {
    while (resuelveCaso());
}