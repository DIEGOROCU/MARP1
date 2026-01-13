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

#include "GrafoValorado.h"

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
    int vertices, aristas;
    cin >> vertices >> aristas;

    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones
    GrafoValorado<int> grafo(vertices);
    for (int i = 0; i < aristas; ++i)
    {
        int v1, v2, valor;
        cin >> v1 >> v2 >> valor;
        grafo.ponArista({v1 - 1, v2 - 1, valor});
    }

    // escribir la solución
    int consultas;
    cin >> consultas;
    for (int i = 0; i < consultas; ++i)
    {
        int origen, destino, tamano;
        cin >> origen >> destino >> tamano;
        origen--;
        destino--;

        bool encontrado = false;
        queue<int> cola;
        vector<bool> visitados(vertices, false);
        cola.push(origen);
        visitados[origen] = true;
        while (!cola.empty() && !encontrado)
        {
            int actual = cola.front();
            cola.pop();

            if (actual == destino)
            {
                encontrado = true;
                break;
            }

            for (const auto &arista : grafo.ady(actual))
            {
                int vecino = arista.otro(actual);
                if (!visitados[vecino] && arista.valor() >= tamano)
                {
                    visitados[vecino] = true;
                    cola.push(vecino);
                }
            }
        }

        cout << (encontrado ? "SI\n" : "NO\n");
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
