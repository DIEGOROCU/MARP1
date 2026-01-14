#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include "GrafoValorado.h"
#include "Digrafo.h"

using namespace std;

using ll = long long;
static const ll INF = numeric_limits<ll>::max() / 4;

// Dijkstra para obtener distancias minimas desde un origen
static vector<ll> dijkstra(GrafoValorado<int> const& grafo, int origen) {
    int n = grafo.V();
    vector<ll> dist(n, INF);

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[origen] = 0;
    pq.push({0, origen});

    while (!pq.empty()) {
        auto [distActual, u] = pq.top();
        pq.pop();
        if (distActual != dist[u]) continue; // entrada obsoleta

        for (auto const& arista : grafo.ady(u)) {
            int v = arista.otro(u);
            ll peso = arista.valor();
            ll nuevaDist = distActual + peso;
            if (nuevaDist < dist[v]) {
                dist[v] = nuevaDist;
                pq.push({nuevaDist, v});
            }
        }
    }
    return dist;
}

bool resuelveCaso() {
    int numVertices;
    cin >> numVertices;
    if (!cin) return false;

    int numAristas;
    cin >> numAristas;

    GrafoValorado<int> gv(numVertices);

    for (int i = 0; i < numAristas; ++i) {
        int origen, destino, peso;
        cin >> origen >> destino >> peso;
        gv.ponArista(Arista<int>(origen - 1, destino - 1, peso));
    }

    int origen = 0;
    int destino = numVertices - 1;

    // 1) Distancia minima desde el origen con Dijkstra
    vector<ll> dist = dijkstra(gv, origen);

    if (dist[destino] == INF) {
        cout << 0 << "\n";
        return true;
    }

    // 2) Construimos DAG con aristas que respetan los caminos minimos
    Digrafo dag(numVertices);
    for (auto const& arista : gv.aristas()) {
        int u = arista.uno();
        int v = arista.otro(u);
        int peso = arista.valor();

        if (dist[u] != INF && dist[u] + peso == dist[v]) dag.ponArista(u, v);
        if (dist[v] != INF && dist[v] + peso == dist[u]) dag.ponArista(v, u);
    }

    // 3) DP sobre el DAG en orden creciente de distancia para contar caminos minimos
    vector<int> orden(numVertices);
    for (int i = 0; i < numVertices; ++i) orden[i] = i;
    sort(orden.begin(), orden.end(), [&](int a, int b) { return dist[a] < dist[b]; });

    vector<unsigned long long> ways(numVertices, 0);
    ways[origen] = 1;

    for (int u : orden) {
        if (dist[u] == INF) break;
        for (int v : dag.ady(u)) {
            ways[v] += ways[u];
        }
    }

    cout << ways[destino] << "\n";
    return true;
}

int main() {
    while (resuelveCaso());
}