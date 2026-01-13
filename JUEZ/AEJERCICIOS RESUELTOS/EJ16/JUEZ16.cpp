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

#include "Grafo.h"

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

bool resuelveCaso()
{

    // leer los datos de la entrada
    int nodos, conexiones;
    cin >> nodos >> conexiones;
    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones
    Grafo g(nodos);
    for (int i = 0; i < conexiones; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g.ponArista(v1 - 1, v2 - 1);
    }
    int consultas;
    cin >> consultas;
    for (int i = 0; i < consultas; i++) {
        int origen, TTL;
        cin >> origen >> TTL;
        origen--;

        // Procesar consulta
        vector<bool> visitados(g.V(), false);
        int visitadosCount = 1;
        visitados[origen] = true;
        queue<int> q;
        if (TTL > 0) {
            for (int vecino : g.ady(origen)) {
                visitados[vecino] = true;
                visitadosCount++;
                q.push(vecino);
            }
        }
        TTL--;
        while (TTL > 0) {
            int size = q.size();
            for (int j = 0; j < size; j++) {
                int actual = q.front();
                q.pop();
                for (int vecino : g.ady(actual)) {
                    if (!visitados[vecino]) {
                        visitados[vecino] = true;
                        visitadosCount++;
                        q.push(vecino);
                    }
                }
            }
            TTL--;
        }
        cout << nodos - visitadosCount << "\n";
    }

    // escribir la solución
    cout << "---\n";

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
