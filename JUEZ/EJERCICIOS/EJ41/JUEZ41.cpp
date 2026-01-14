#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "GrafoValorado.h"
#include "PriorityQueue.h"

static const long long INF = (1LL << 62);

struct Estado {
    long long distancia;
    int vertice;
};

struct ComparadorDistancia {
    bool operator()(Estado const& a, Estado const& b) const {
        return a.distancia < b.distancia;
    }
};

// Dijkstra para calcular distancias minimas desde un origen
template <typename Valor>
vector<long long> dijkstra(const GrafoValorado<Valor>& grafo, int origen) {
    int n = grafo.V();
    vector<long long> dist(n, INF);
    PriorityQueue<Estado, ComparadorDistancia> pq;

    dist[origen] = 0;
    pq.push({0, origen});

    while (!pq.empty()) {
        Estado actual = pq.top();
        pq.pop();

        long long distActual = actual.distancia;
        int u = actual.vertice;

        if (distActual != dist[u]) continue; // estado viejo

        for (auto const& arista : grafo.ady(u)) {
            int w = arista.otro(u);
            long long nuevaDist = distActual + (long long)arista.valor();
            if (nuevaDist < dist[w]) {
                dist[w] = nuevaDist;
                pq.push({nuevaDist, w});
            }
        }
    }

    return dist;
}

bool resuelveCaso() {
    int numVertices, numAristas;
    if (!(cin >> numVertices >> numAristas)) return false;

    GrafoValorado<int> grafo(numVertices);

    for (int i = 0; i < numAristas; ++i) {
        int origen, destino, coste;
        cin >> origen >> destino >> coste;
        grafo.ponArista(Arista<int>(origen - 1, destino - 1, coste));
    }

    // Calcular distancias desde norte (vertice 0) y sur (vertice N-1)
    vector<long long> distNorte = dijkstra(grafo, 0);
    vector<long long> distSur = dijkstra(grafo, numVertices - 1);

    int mitadIntermedia = (numVertices - 2) / 2;

    long long costoBase = 0;
    vector<long long> diferencias;
    diferencias.reserve(numVertices - 2);

    // Calcular delta para cada vertice intermedio
    for (int v = 1; v <= numVertices - 2; ++v) {
        long long costoDesdeSur = 2LL * distSur[v];
        long long costoDesdeNorte = 2LL * distNorte[v];
        costoBase += costoDesdeSur;
        diferencias.push_back(costoDesdeNorte - costoDesdeSur);
    }

    // Seleccionar las menores diferencias para minimizar costo
    sort(diferencias.begin(), diferencias.end());
    long long mejora = 0;
    for (int i = 0; i < mitadIntermedia; ++i) mejora = mejora + diferencias[i];

    cout << (costoBase + mejora) << "\n";
    return true;
}

int main() {
    while (resuelveCaso());
}