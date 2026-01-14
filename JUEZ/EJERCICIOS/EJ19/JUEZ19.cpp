/*@ <authors>
 *
 * Diego Rodriguez Cubeo DG30
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>

#include <stack>
#include <queue>
#include <deque>

#include <list>
#include <forward_list>

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <tuple>

#include "Digrafo.h"

using namespace std;

/*@ <answer>

   Escribe aquí un comentario general sobre la solución, explicando cómo
   se resuelve el problema y cuál es el coste de la solución, en función
   del tamaño del problema.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void topologico(Digrafo const& g, int v, vector<bool>& marcados, vector<int>& orden, bool & ciclo) {
    marcados[v] = true;
    for (int w : g.ady(v)) {
        if (!marcados[w]) {
            topologico(g, w, marcados, orden, ciclo);
        }
        else if (find(orden.begin(), orden.end(), w) == orden.end()) {
            ciclo = true; // Hemos encontrado un ciclo
        }
    }
    orden.push_back(v);
}

bool resuelveCaso()
{

    // leer los datos de la entrada
    int vertices, aristas;
    cin >> vertices >> aristas;

    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones
    Digrafo g(vertices);
    for (int i = 0; i < aristas; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        g.ponArista(v1 - 1, v2 - 1);
    }

    // Realicemos el orden topológico
    vector<bool> marcados(vertices, false);
    vector<int> orden;
    bool ciclo = false;

    for (int v = 0; v < vertices; ++v) {
        if (!marcados[v]) {
            topologico(g, v, marcados, orden, ciclo);
        }
    }

    // escribir la solución
    if (ciclo) {
        cout << "IMPOSIBLE\n";
    }
    else {
        reverse(orden.begin(), orden.end());
        for (int v : orden) {
            cout << v + 1 << " ";
        }
        cout << "\n";
    }

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
