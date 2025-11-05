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

/*
   La idea detras de la solución es utilizar una cola de prioridad para ir combinando los números más pequeños primero.
   El coste es O(n log n) siendo n el número de elementos iniciales, ya que en cada combinación se realizan dos extracciones y una inserción en la cola de prioridad,
   cada una de ellas con coste logarítmico, y se realizan n-1 combinaciones.
*/

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
      
      // Lectura de los números
      PriorityQueue<int> numeros;
      for (int i = 0; i < n; ++i)
      {
         int num;
         cin >> num;
         numeros.push(num);
      }

      int suma = 0;
      // Resolución del caso
      suma = numeros.resuelveCaso();

      // escribir los resultados
      cout << suma << endl;
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
