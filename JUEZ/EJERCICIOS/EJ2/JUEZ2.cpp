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

#include "TreeSet_AVL.h"

using namespace std;

/*@ <answer>

 La idea del problema se basa principalmente en incluir en la clase Set el contador tam_i que almacena el número de nodos del hijo izquierdo + 1 (la raíz). De esta forma, al buscar el k-ésimo elemento, podemos comparar k con tam_i y decidir si el k-ésimo elemento está en el hijo izquierdo, en el hijo derecho o es la raíz.
 Una vez tenemos esto, la implementación de la función kesimo es sencilla y se basa en una función recursiva auxiliar que recibe como parámetros el nodo actual y el índice k. 
 La función compara k con tam_i del nodo actual y decide en qué subárbol buscar el k-ésimo elemento o si es la raíz. 
 Si k es menor que tam_i, el k-ésimo elemento está en el hijo izquierdo, si es mayor, está en el hijo derecho (restando tam_i + 1 a k para ajustar el índice, ya que son la cantidad de nodos del hijo izquierdo + la raíz) y si es igual, la raíz es el k-ésimo elemento.
 Si k está fuera de rango, la función lanza una excepción std::out_of_range, que es capturada en la función resuelveCaso para imprimir "??".

 Complejidad:
   - La adicion de tam_i no afecta a la complejidad de las operaciones de inserción y borrado, ya que se puede actualizar en O(1) (en cantidad y complejidad) en las funciones donde esta implementado.
   - La función kesimo tiene una complejidad O(log n) con n siendo el número de elementos en el conjunto (log n = altura del arbol), ya que en cada llamada recursiva se reduce el problema a uno de los subárboles (izquierdo o derecho), lo cual implica que se reduce el tamaño del problema a la mitad en cada paso, o analogamente, se desciende un nivel en el árbol, siendo ambas complejidades iguales (log n = altura del árbol).

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
      // Leemos los n numeros del set
      Set<int> conjunto;
      for (int i = 0; i < n; ++i) {
         int num;
         cin >> num;
         conjunto.insert(num);
      }
      
      int cantPreguntas;
      cin >> cantPreguntas;

      // escribir la solución
      for (int i = 0; i < cantPreguntas; ++i) {
         int num;
         cin >> num;
         try {
            cout << conjunto.kesimo(num - 1) << "\n";
         } catch (std::out_of_range) {
            cout << "??\n";
         }
         
      }

      cout << "---\n";

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
