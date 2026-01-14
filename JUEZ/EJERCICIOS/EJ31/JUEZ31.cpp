#include <iostream>
#include <vector>
#include <limits>
#include "GrafoValorado.h"
#include "PriorityQueue.h"

using namespace std;

struct Estado {
    long long distancia;
    int vertice;
};

// La PriorityQueue es de minimos, asi que "a antes que b" si a.distancia < b.distancia
struct CompEstado {
    bool operator()(Estado const& a, Estado const& b) const {
        return a.distancia < b.distancia;
    }
};

bool resuelveCaso() {
    long long distanciaMaxima;
    int numPueblos, numCaminos;
    if (!(cin >> distanciaMaxima >> numPueblos >> numCaminos)) return false; // EOF

    GrafoValorado<long long> grafo(numPueblos);

    for (int i = 0; i < numCaminos; ++i) {
        int origen, destino;
        long long tiempo;
        cin >> origen >> destino >> tiempo;
        grafo.ponArista(Arista<long long>(origen - 1, destino - 1, tiempo)); // 1..P -> 0..P-1
    }

    int numBorriqueros;
    cin >> numBorriqueros;
    vector<int> borriqueros(numBorriqueros);
    for (int i = 0; i < numBorriqueros; ++i) {
        cin >> borriqueros[i];
        --borriqueros[i];
    }

    const long long INF = numeric_limits<long long>::max() / 4; // Infinito para inicializar distancias
    vector<long long> dist(numPueblos, INF);
    vector<char> fijado(numPueblos, 0);

    PriorityQueue<Estado, CompEstado> pq;

    // Multi-origen: todos los borriqueros empiezan a distancia 0
    for (int pueblo : borriqueros) {
        if (dist[pueblo] > 0) {
            dist[pueblo] = 0;
            pq.push(Estado{0, pueblo});
        }
    }

    int pueblosAlcanzables = 0;

    while (!pq.empty()) {
        Estado actual = pq.top();
        pq.pop();

        long long distActual = actual.distancia;
        int vertice = actual.vertice;
        
        // Si esta fijado => estado viejo (ya fijamos vertice con una distancia menor)

        if (!fijado[vertice]) {
            fijado[vertice] = 1;

            if (distActual > distanciaMaxima) break; // el minimo ya supera D, podemos parar

            ++pueblosAlcanzables;

            for (auto const& arista : grafo.ady(vertice)) {
                int vecino = arista.otro(vertice);
                long long nuevaDist = distActual + arista.valor();

                if (!fijado[vecino] && nuevaDist < dist[vecino]) {
                    dist[vecino] = nuevaDist;
                    pq.push(Estado{nuevaDist, vecino});
                }
            }
        }
    }

    cout << pueblosAlcanzables << "\n";
    return true;
}

int main() {
    while (resuelveCaso()) {}
    return 0;
}