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

 La idea es usar una cola de prioridad para simular las cajas, llevando la cuenta del tiempo que ha ido pasando para saber cuando se libera cada caja, asi, tras procesar a todos los clientes, la caja que quede en la cima de la cola sera la que toque a continuacion, es decir, la caja para Ismael.
 El coste es O(n log k) siendo n el numero de clientes y k el numero de cajas, ya que por cada cliente hacemos una operacion de insercion y eliminacion en la cola de prioridad que tiene k elementos, ambas operaciones en O(log k), y entre medias hacemos operaciones y comparaciones en tiempo y cantidad constante.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso()
{

   // leer los datos de la entrada

   int cajas, clientes;
   cin >> cajas >> clientes;
    
   if (cajas == 0 && clientes == 0)
      return false;

   else
   {
      // resolver el caso posiblemente llamando a otras funciones
        PriorityQueue<pair<int, int>, less<pair<int, int>>> pq;
        for (int i = 0; i < cajas; ++i) {
            pq.push({0, i});
        }
        int tiempoTotal = 0;
        for (int i = 0; i < clientes; ++i) {
            int tiempo;
            cin >> tiempo;
            auto caja = pq.top();
            pq.pop();
            tiempoTotal += caja.first - tiempoTotal;
            caja.first += tiempo;
            pq.push(caja);
        }

      // escribir la solución
      cout << pq.top().second + 1 << endl;

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
