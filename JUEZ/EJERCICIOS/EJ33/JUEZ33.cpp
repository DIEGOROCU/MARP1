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
    int ciudades;
    cin >> ciudades;

    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones
    vector<int> enemigos(ciudades);;
    for (int i = 0; i < ciudades; ++i)
    {
        cin >> enemigos[i];
    }
    sort(enemigos.begin(), enemigos.end());
    vector<int> defensores(ciudades);
    for (int i = 0; i < ciudades; ++i)
    {
        cin >> defensores[i];
    }
    sort(defensores.begin(), defensores.end());

    // escribir la solución
    int e = 0, d = 0;
    int ciudadesSeguras = 0;
    while (e < ciudades && d < ciudades)
    {
        if (defensores[d] >= enemigos[e])
        {
            ++ciudadesSeguras;
            ++e;
            ++d;
        }
        else
        {
            ++d;
        }
    }

    cout << ciudadesSeguras << "\n";

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
