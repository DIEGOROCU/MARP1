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

#include "PriorityQueue.h"

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

    int edad, cantParejas;
    cin >> edad >> cantParejas;

    if (edad == 0 && cantParejas == 0)
        return false;

    else
    {
        // resolver el caso posiblemente llamando a otras funciones
        PriorityQueue<int, greater<int>> pq_mayores;
        PriorityQueue<int, less<int>> pq_menores;
        //pq_mayores.push(edad);
        //pq_menores.push(edad);
        for (int i = 0; i < cantParejas; ++i)
        {
            int edad1, edad2;
            cin >> edad1 >> edad2;
            if (edad1 > edad && edad2 > edad)
            {
                pq_menores.push(edad1);
                pq_menores.push(edad2);
                pq_mayores.push(edad);
                edad = pq_menores.top();;
                pq_menores.pop();

            }
            else if (edad1 < edad && edad2 < edad)
            {
                pq_mayores.push(edad1);
                pq_mayores.push(edad2);
                pq_menores.push(edad);
                edad = pq_mayores.top();
                pq_mayores.pop();
            }
            else
            {
                if (edad1 > edad)
                {
                    pq_menores.push(edad1);
                    pq_mayores.push(edad2);
                }
                else
                {
                    pq_menores.push(edad2);
                    pq_mayores.push(edad1);
                }
            }
            cout << edad << " ";
        }


        // escribir la solución

        cout << "\n";

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
