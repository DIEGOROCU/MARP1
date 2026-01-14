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

    int n;
    cin >> n;

    if (n == 0)
        return false;

    else
    {
        // resolver el caso posiblemente llamando a otras funciones
        vector<int> puntosRivales(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> puntosRivales[i];
        }
        // Ordenamos de menor a mayor
        sort(puntosRivales.begin(), puntosRivales.end());

        vector<int> puntosJugadores(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> puntosJugadores[i];
        }
        // Ordenamos de mayor a menor
        sort(puntosJugadores.begin(), puntosJugadores.end(), greater<int>());

        int sumaDiferencias = 0;
        for (int i = 0; i < n; ++i)
        {
            if (puntosJugadores[i] > puntosRivales[i])
            {
                sumaDiferencias += puntosJugadores[i] - puntosRivales[i];
            }
            else // Si no es mayor, no nos interesa seguir comprobando
            {
                break;
            }
        }

        // escribir la solución
        cout << sumaDiferencias << "\n";

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
