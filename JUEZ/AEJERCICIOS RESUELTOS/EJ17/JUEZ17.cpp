#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

#include "Grafo.h"

using namespace std;

static const int INF = numeric_limits<int>::max();

// BFS para calcular distancias mínimas desde un nodo origen
vector<int> bfsDist(const Grafo &grafo, int origen)
{
    int numVertices = grafo.V();
    vector<int> distancias(numVertices, INF);
    queue<int> cola;

    distancias[origen] = 0;
    cola.push(origen);

    while (!cola.empty())
    {
        int verticeActual = cola.front();
        cola.pop();
        for (int vecino : grafo.ady(verticeActual))
        {
            if (distancias[vecino] == INF)
            {
                distancias[vecino] = distancias[verticeActual] + 1;
                cola.push(vecino);
            }
        }
    }
    return distancias;
}

bool resuelveCaso()
{
    int N, C;
    int A, L, T;
    if (!(cin >> N >> C >> A >> L >> T))
        return false;

    Grafo g(N);
    for (int i = 0; i < C; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g.ponArista(u, v);
    }

    int a = A - 1, l = L - 1, t = T - 1;

    // Distancias m�nimas (en n� de tramos) desde Alex, Lucas y el trabajo
    vector<int> dA = bfsDist(g, a);
    vector<int> dL = bfsDist(g, l);
    vector<int> dT = bfsDist(g, t); // dT[v] = distancia v -> trabajo

    long long mejor = (long long)INF * 3;
    for (int v = 0; v < N; ++v)
    {
        long long cand = (long long)dA[v] + dL[v] + dT[v];
        if (cand < mejor)
            mejor = cand;
    }

    cout << mejor << "\n";
    return true;
}

int main()
{
    while (resuelveCaso())
        ;
}