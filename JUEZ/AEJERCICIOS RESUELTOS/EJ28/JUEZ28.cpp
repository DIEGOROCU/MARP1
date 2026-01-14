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

#include "DigrafoValorado.h"

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

    int nodos;
    cin >> nodos;

    if (nodos == 0)
        return false;

    else
    {
        // resolver el caso posiblemente llamando a otras funciones
        vector<int> tiemposCarga(nodos);
        for (int i = 0; i < nodos; ++i)
        {
            cin >> tiemposCarga[i];
        }

        DigrafoValorado<int> enlaces(nodos);
        int conexiones;
        cin >> conexiones;
        for (int i = 0; i < conexiones; ++i)
        {
            int origen, destino, tiempo;
            cin >> origen >> destino >> tiempo;
            enlaces.ponArista({origen - 1, destino - 1, tiempo}); // 1..N -> 0..N-1
        }

        // Busqueda del camino mínimo con tiempos de carga
        int origen = 0, destino = nodos - 1;
        vector<bool> visitado(nodos, false);
        queue<int> q;
        visitado[origen] = true;
        q.push(origen);
        vector<int> padre(nodos, -1);
        vector<int> distancia(nodos, 0);
        distancia[origen] = tiemposCarga[origen];

        while (!q.empty()) {
            int actual = q.front();
            q.pop();
            for (const auto& arista : enlaces.ady(actual)) {
                int vecino = arista.hasta();
                if (!visitado[vecino]) {
                    visitado[vecino] = true;
                    padre[vecino] = actual;
                    distancia[vecino] = distancia[actual] + arista.valor() + tiemposCarga[vecino];
                    q.push(vecino);
                }
                else if (distancia[actual] + arista.valor() + tiemposCarga[vecino] < distancia[vecino]) {
                    padre[vecino] = actual;
                    distancia[vecino] = distancia[actual] + arista.valor() + tiemposCarga[vecino];
                    q.push(vecino);
                }
            }
        }   

        // escribir la solución

        if (visitado[destino]) {
            cout << distancia[destino] << "\n";
        }
        else {
            cout << "IMPOSIBLE\n";
        }

        return true;
    }
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
