
/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (DGXX) de los autores de la solución.
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

void resuelveCaso()
{

    // leer los datos de la entrada
    int cantidadPersonas, cantidadParejas;
    cin >> cantidadPersonas >> cantidadParejas;
    // resolver el caso posiblemente llamando a otras funciones
    Grafo g(cantidadPersonas);
    for (int i = 0; i < cantidadParejas; ++i)
    {
        int persona1, persona2;
        cin >> persona1 >> persona2;
        g.ponArista(persona1 - 1, persona2 - 1);
    }

    // escribir la solución
    int grupoMaximo = 0;
    vector<bool> visitado(cantidadPersonas, false);
    for (int i = 0; i < cantidadPersonas; ++i)
    {
        if (!visitado[i])
        {
            int tamanoGrupo = 0;
            stack<int> pila;
            pila.push(i);
            visitado[i] = true;
            while (!pila.empty())
            {
                int v = pila.top();
                pila.pop();
                ++tamanoGrupo;
                for (int w : g.ady(v))
                {
                    if (!visitado[w])
                    {
                        visitado[w] = true;
                        pila.push(w);
                    }
                }
            }
            grupoMaximo = max(grupoMaximo, tamanoGrupo);
        }
    }
    cout << grupoMaximo << "\n";
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

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
