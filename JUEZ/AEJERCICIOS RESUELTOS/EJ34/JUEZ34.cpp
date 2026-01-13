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
    int cantNinos, cantCamisetas;
    cin >> cantNinos >> cantCamisetas;

    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones
    vector<int> ninos(cantNinos);
    for (int i = 0; i < cantNinos; ++i)
    {
        cin >> ninos[i];
    }
    sort(ninos.begin(), ninos.end());
    vector<int> camisetas(cantCamisetas);
    for (int i = 0; i < cantCamisetas; ++i)
    {
        cin >> camisetas[i];
    }
    sort(camisetas.begin(), camisetas.end());

    int camisetasUsadas = 0;
    int n = 0; // índice para los niños
    int c = 0; // índice para las camisetas
    while (n < cantNinos && c < cantCamisetas)
    {
        if (camisetas[c] == ninos[n] || camisetas[c] == ninos[n] + 1)
        {
            ++camisetasUsadas;
            ++n;
            ++c;
        }
        else if (camisetas[c] < ninos[n])
        {
            ++c;
        }
        else // camisetas[c] > ninos[n] + 1
        {
            ++n;
        }
    }

    // escribir la solución
    cout << cantNinos - camisetasUsadas << "\n";

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
