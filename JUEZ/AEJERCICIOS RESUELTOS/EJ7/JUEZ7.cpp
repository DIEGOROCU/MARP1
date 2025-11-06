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
    int partituras, instrumentos;
    cin >> partituras >> instrumentos;

    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    PriorityQueue<tuple<float, int, int>, greater<tuple<float, int, int>>> pq;
    for (int i = 0; i < instrumentos; ++i)
    {
        int cantMusicos;
        cin >> cantMusicos;
        pq.push(make_tuple(cantMusicos, cantMusicos, 1));
    }
    for (int i = 0; i < partituras - instrumentos; ++i) {
        auto [cantPorPartitura, total, cantPartituras] = pq.top();
        cantPartituras++;
        cantPorPartitura = float(total) / cantPartituras;
        pq.pop();
        pq.push(make_tuple(cantPorPartitura, total, cantPartituras));
    }

    auto [cantPorPartitura, total, cantPartituras] = pq.top();
    if (cantPartituras == 0) {
        cout << total << "\n";
    }
    else {
        int cantMaxi = (total / cantPartituras) + (total % cantPartituras != 0 ? 1 : 0);
        cout << cantMaxi << "\n";
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
