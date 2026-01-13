#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // iota
#include "GrafoValorado.h"

using namespace std;

// Union-Find / DSU
// Estructura Union-Find para Kruskal
class UF {
    vector<int> parent;
    vector<int> rango;
public:
    UF(int n) : parent(n), rango(n, 0) { iota(parent.begin(), parent.end(), 0); }

    int find(int x) {
        if (parent[x] == x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rango[a] < rango[b]) swap(a, b);
        parent[b] = a;
        if (rango[a] == rango[b]) ++rango[a];
        return true;
    }

    int numSets() {
        int n = (int)parent.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) if (find(i) == i) ++cnt;
        return cnt;
    }
};

bool resuelveCaso() {
    int numIslas;
    if (!(cin >> numIslas)) return false; // EOF
    int numPuentes;
    cin >> numPuentes;

    GrafoValorado<int> grafo(numIslas);
    for (int i = 0; i < numPuentes; ++i) {
        int origen, destino, coste;
        cin >> origen >> destino >> coste;
        grafo.ponArista(Arista<int>(origen - 1, destino - 1, coste)); // 1..I -> 0..I-1
    }

    vector<Arista<int>> aristas = grafo.aristas();
    sort(aristas.begin(), aristas.end(),
        [](Arista<int> const& e1, Arista<int> const& e2) {
            return e1.valor() < e2.valor();
        });

    UF conjuntos(numIslas);
    long long int costeTotal = 0;
    int aristasUsadas = 0;

    // Kruskal: tomamos aristas en orden creciente si conectan componentes distintas
    for (auto const& arista : aristas) {
        int v = arista.uno();
        int w = arista.otro(v);
        if (conjuntos.unite(v, w)) {
            costeTotal += arista.valor();
            ++aristasUsadas;
            if (aristasUsadas == numIslas - 1) break; // MST completo
        }
    }

    if (numIslas == 0) { // por si acaso, aunque el enunciado dice I>=1
        cout << 0 << "\n";
    }
    else if (aristasUsadas == numIslas - 1) {
        cout << costeTotal << "\n";
    }
    else {
        cout << "No hay puentes suficientes\n";
    }

    return true;
}

int main() {
    while (resuelveCaso()) {}
    return 0;
}