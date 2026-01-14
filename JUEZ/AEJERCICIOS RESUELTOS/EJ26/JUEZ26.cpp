#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>     // iota
#include "GrafoValorado.h"

using namespace std;

// Estructura Union-Find para componentes de carreteras
class UF {
    vector<int> parent;
    vector<int> rango;
public:
    UF(int n) : parent(n), rango(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rango[a] < rango[b]) swap(a, b);
        parent[b] = a;
        if (rango[a] == rango[b]) ++rango[a];
        return true;
    }
    int countSets() {
        int n = (int)parent.size();
        int cont = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i) cont++;
        }
        return cont;
    }
};

bool resuelveCaso() {
    int numCiudades, numCarreteras;
    int costeAeropuerto;
    if (!(cin >> numCiudades >> numCarreteras >> costeAeropuerto)) return false; // EOF

    GrafoValorado<int> grafo(numCiudades);
    for (int i = 0; i < numCarreteras; ++i) {
        int origen, destino, coste;
        cin >> origen >> destino >> coste;
        // Entrada: 1..N -> interno: 0..N-1
        grafo.ponArista(Arista<int>(origen - 1, destino - 1, coste));
    }

    // Lista de aristas sin duplicados
    vector<Arista<int>> aristas = grafo.aristas();

    // Ordenamos por coste para Kruskal parcial
    sort(aristas.begin(), aristas.end(),
        [](Arista<int> const& e1, Arista<int> const& e2) {
            return e1.valor() < e2.valor();
        });

    UF uf(numCiudades);
    long long int costeCarreteras = 0;

    // Kruskal parcial: solo usamos aristas mas baratas que un aeropuerto
    for (auto const& e : aristas) {
        if (e.valor() >= costeAeropuerto) break; // al estar ordenadas, ninguna posterior interesa

        int v = e.uno();
        int w = e.otro(v);

        if (uf.unite(v, w)) {
            costeCarreteras += e.valor();
        }
    }

    int aeropuertos = uf.countSets();
    long long int costeTotal = costeCarreteras + 1LL * aeropuertos * costeAeropuerto;

    cout << costeTotal << " " << aeropuertos << "\n";
    return true;
}

int main() {
    while (resuelveCaso());
}