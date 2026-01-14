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
    int numVertices, numAristas;
    cin >> numVertices >> numAristas;

    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones
    Grafo grafo(numVertices);
    for (int i = 0; i < numAristas; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        grafo.ponArista(v1, v2);
    }

    // escribir la solución
    bool esLibre = true;
    vector<bool> visitado(numVertices, false);
    int cantidadVisitados = 0;
    
    queue<pair<int,int>> q;
    if (numVertices > 0) {
        q.push({0, -1}); // {vertice, padre}
        visitado[0] = true;
        cantidadVisitados++;
    }

    while (!q.empty() && esLibre) {
        auto [v, padre] = q.front();
        q.pop();

        for (int w : grafo.ady(v)) {
            if (!visitado[w]) {
                visitado[w] = true;
                cantidadVisitados++;
                q.push({w, v});
            }
            else if (w != padre) {
                esLibre = false; // ciclo detectado
                break;
            }
        }
    }

    if (cantidadVisitados != numVertices)
        esLibre = false; // no es conexo


    if (esLibre)
        cout << "SI\n";
    else
        cout << "NO\n";

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
