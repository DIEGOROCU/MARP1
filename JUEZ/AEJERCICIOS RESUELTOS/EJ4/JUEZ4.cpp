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

    El objetivo es simular la UCM llevando cuenta del momento al que le toca salir a cada numero.
    Para ello, usaremos una cola de prioridad donde cada elemento es una tupla compuesta por:
        - El tiempo al que le toca salir el numero
        - El numero en si
        - Cada cuanto tiempo vuelve a salir ese numero (prioridad)
    Sabiendo esto, utilizamos una cola de prioridad con el comparador "less" para que nos devuelva primero el que tiene el tiempo de salida menor, es decir, debe salir antes, y en caso de empate, el que tenga el numero menor.
    La simulación recorre tantas iteraciones como tiempo se le indique, y en cada iteración:
        - Sacamos el elemento con mayor prioridad (el que debe salir antes)
        - Actualizamos el tiempo pasado
        - Reinsertamos el elemento en la cola con su nuevo tiempo de salida (tiempo actual + prioridad)
        - Incrementamos el contador de iteraciones
    Todo esto se hace en tiempo O(t log n), siendo t el tiempo total a simular y n el número de elementos que habia inicialmente en la cola (que se mantiene constante).
    Esto es ya que en cada una de las t iteraciones hacemos una extracción y una inserción en la cola de prioridad, ambas operaciones en tiempo O(log n), y varias comprobaciones y asignaciones en tiempo y cantidad constante.
    Ademas, la cola nunca cambia de tamaño, ya que por cada elemento que sacamos, volvemos a insertar uno.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

void UCM(int const tiempo, PriorityQueue<tuple<int, int, int>, less<tuple<int, int, int>>>& cola_) {
    int cont = 0;
    int tiempoPasado = 0;
    while(!cola_.empty() && cont < tiempo){
        auto[tocaActual, numero, prioridad] = cola_.top();
        cout << numero << "\n";
        cola_.pop();
        tiempoPasado += tocaActual - tiempoPasado;
        cola_.push({tocaActual + prioridad, numero, prioridad});
        cont++;
    }
}

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
        PriorityQueue<tuple<int, int, int>, less<tuple<int, int, int>>> cola_;
        for (int i = 0; i < n; ++i) {
            int num, prioridad;
            cin >> num >> prioridad;
            cola_.push({prioridad, num, prioridad});
        }
        int tiempo;
        cin >> tiempo;

        UCM(tiempo, cola_);

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
