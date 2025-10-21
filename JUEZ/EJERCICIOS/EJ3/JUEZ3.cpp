
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

bool esMonticuloMaximos(vector<int> V, int n) {
            for (int i = 0; i <= (n - 2) / 2; i++) { // Recorremos nodos con hijos
                int izq = 2 * i + 1; // Hijo izquierdo
                int der = 2 * i + 2; // Hijo derecho
                if (izq < n && V[i] < V[izq]) {
                    return false; // Violación de la propiedad del montículo
                }
                if (der < n && V[i] < V[der]) {
                    return false; // Violación de la propiedad del montículo
                }
            }
            return true; // Es un montículo de máximos
}

void resuelveCaso()
{

   // leer los datos de la entrada
   int n;
   std::cin >> n;
   vector<int> V(n);
   for (int i = 0; i < n; ++i) {
      std::cin >> V[i];
   }

   // resolver el caso posiblemente llamando a otras funciones
   if (esMonticuloMaximos(V, n)) {
       std::cout << "Es un montículo de máximos\n";
   } else {
       std::cout << "No es un montículo de máximos\n";
   }

   // escribir la solución
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
