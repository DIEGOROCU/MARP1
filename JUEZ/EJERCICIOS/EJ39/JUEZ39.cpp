
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
    int cantPilas, voltajeMinimo;
    cin >> cantPilas >> voltajeMinimo;

    // resolver el caso posiblemente llamando a otras funciones
    vector<int> pilas(cantPilas);
    for (int i = 0; i < cantPilas; ++i)
        cin >> pilas[i];
    sort(pilas.begin(), pilas.end());

    int cantCochesPosibles = 0;
    int i = 0, j = cantPilas - 1;
    while (i < j)
    {
        if (pilas[i] + pilas[j] >= voltajeMinimo)
        {
            ++cantCochesPosibles;
            ++i;
            --j;
        }
        else
        {
            ++i;
        }
    }

    // escribir la solución
    cout << cantCochesPosibles << "\n";
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
