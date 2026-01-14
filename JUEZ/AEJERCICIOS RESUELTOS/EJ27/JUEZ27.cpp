#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "GrafoValorado.h"

using namespace std;

using ll = long long int;
static const ll INF = numeric_limits<ll>::max() / 4;

struct Query {
    int origen;
    int destino;
};

struct DijkstraResult {
    vector<ll> dist;
    vector<int> parent;
};

static DijkstraResult dijkstra(GrafoValorado<int> const& grafo, int origen) {
    int n = grafo.V();
    vector<ll> dist(n, INF);
    vector<int> parent(n, -1);

    // (distancia, vertice)
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[origen] = 0;
    parent[origen] = origen;
    pq.push({ 0, origen });

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du != dist[u]) continue; // entrada vieja

        for (auto const& ar : grafo.ady(u)) {
            int v = ar.otro(u);
            ll w = ar.valor();
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({ dist[v], v });
            }
        }
    }

    return { dist, parent };
}

// Reconstruye camino desde origen a destino usando los padres calculados
static vector<int> reconstruyeCamino(int origen, int destino, vector<int> const& parent) {
    vector<int> path;
    if (parent[destino] == -1) return path; // no alcanzable

    int cur = destino;
    while (cur != origen) {
        path.push_back(cur);
        cur = parent[cur];
        if (cur == -1) { // seguridad extra
            path.clear();
            return path;
        }
    }
    path.push_back(origen);
    reverse(path.begin(), path.end());
    return path;
}

bool resuelveCaso() {
    int numVertices, numAristas;
    cin >> numVertices >> numAristas;
    if (!cin) return false;

    GrafoValorado<int> grafo(numVertices);

    for (int i = 0; i < numAristas; ++i) {
        int origen, destino, peso;
        cin >> origen >> destino >> peso;
        grafo.ponArista(Arista<int>(origen - 1, destino - 1, peso));
    }

    int numConsultas;
    cin >> numConsultas;
    vector<Query> queries(numConsultas);
    for (int i = 0; i < numConsultas; ++i) {
        int origen, destino;
        cin >> origen >> destino;
        queries[i] = { origen - 1, destino - 1 };
    }

    // Optimizacion: agrupar por origen para evitar repetir Dijkstra
    vector<vector<int>> idxPorOrigen(numVertices);
    for (int i = 0; i < numConsultas; ++i) {
        idxPorOrigen[queries[i].origen].push_back(i);
    }

    vector<ll> ansDist(numConsultas, INF);
    vector<vector<int>> ansPath(numConsultas);

    for (int origen = 0; origen < numVertices; ++origen) {
        if (idxPorOrigen[origen].empty()) continue;

        auto res = dijkstra(grafo, origen);

        for (int qi : idxPorOrigen[origen]) {
            int destino = queries[qi].destino;
            if (res.dist[destino] == INF) {
                ansDist[qi] = INF;
            }
            else {
                ansDist[qi] = res.dist[destino];
                ansPath[qi] = reconstruyeCamino(origen, destino, res.parent);
            }
        }
    }

    // Salida en el orden original de las consultas
    for (int i = 0; i < numConsultas; ++i) {
        if (ansDist[i] == INF || ansPath[i].empty()) {
            cout << "NO LLEGA\n";
        }
        else {
            cout << ansDist[i] << ": ";
            // imprimir puntos en 1..N con formato "a-> b-> c" (con espacio despues de ->)
            cout << (ansPath[i][0] + 1);
            for (size_t j = 1; j < ansPath[i].size(); ++j) {
                cout << "-> " << (ansPath[i][j] + 1);
            }
            cout << "\n";
        }
    }

    cout << "---\n";
    return true;
}

int main() {
    while (resuelveCaso());
}