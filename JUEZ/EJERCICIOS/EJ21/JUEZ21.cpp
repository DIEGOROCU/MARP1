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
    vector<int> salientes(vertices, 0), entrantes(vertices, 0);
    for (int i = 0; i < aristas; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        salientes[v1]++;
        entrantes[v2]++;
    }

    int i = 0;
    bool haySumideros = false;
    while (i < vertices && !haySumideros)
    {
        if (salientes[i] == 0 && entrantes[i] == vertices - 1)
        {
            cout << "SI " << i << "\n";
            haySumideros = true;
        }
        i++;
    }

    if (!haySumideros)
    {
        cout << "NO" << "\n";
    }

    // escribir la solución

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
