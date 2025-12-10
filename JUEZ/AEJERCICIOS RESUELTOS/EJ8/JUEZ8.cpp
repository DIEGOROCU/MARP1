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

    La idea del ejercicio es ir añadiendo las tareas a una cola de prioridad, segun su inicio (el resto de datos son solo para las comprobaciones, no importan para el orden de la cola siempre que no haya repeticiones, en cuyo caso se detectaran).
    Luego vamos recorriendo las tareas segun su inicio, eliminando de la cola a las unicas y reinsertando las repetitivas con su nuevo inicio y fin.
    Si en algun momento una tarea empieza antes de que haya acabado la anterior (para ello llevamos la cuenta del tiempo transcurrido), entonces hay un solapamiento y se debe indicar que SI se solapan tareas.
    En caso de que se recorran todas las tareas sin solapamientos (llegando a comprobar hasta que el inicio de todas las tareas es mayor o igual que el tiempo total disponible), se indica que NO hay solapamientos.
    El coste en caso peor es O( (nr + r)log(nr + r) + tlog(nr + r) ) siendo nr el numero de tareas no repetitivas, r el numero de tareas repetitivas y t el tiempo total disponible.
    Esto es debido a que primero hacemos nr + r inserciones en la cola (cada una de coste log(nr + r)) y luego en el peor caso hacemos t extracciones e inserciones (cada una de coste log(nr + r)), ya que en el peor caso podriamos tener una tarea repetitiva cada unidad de tiempo, y sin solapamientos, lo que haria recorrer las t unidades de tiempo.
    Durante este proceso tambien hacemos comparaciones y asignaciones en cantidades y costes constantes, por lo que no afectan al coste final.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso()
{

    int tareasUnicas, tareasRepetidas, tiempoTotal;
    cin >> tareasUnicas >> tareasRepetidas >> tiempoTotal;

    if (!cin)
    {
        return false;
    }

    PriorityQueue<tuple<int, int, int, int>, less<tuple<int, int, int, int>>> pq;
    for (int i = 0; i < tareasUnicas; ++i)
    {
        int inicio, fin;
        cin >> inicio >> fin;
        pq.push(make_tuple(inicio, fin, 0, 0));
    }
    for (int i = 0; i < tareasRepetidas; ++i)
    {
        int inicio, fin, intervalo;
        cin >> inicio >> fin >> intervalo;
        pq.push(make_tuple(inicio, fin, intervalo, 1));
    }

    int tiempo = 0;
    while (!pq.empty() && get<0>(pq.top()) < tiempoTotal)
    {
        auto [inicio, fin, intervalo, esRepetitiva] = pq.top();
        pq.pop();
        if (inicio >= tiempo)
        {
            tiempo = fin;
            if (esRepetitiva == 1)
            {
                pq.push(make_tuple(inicio + intervalo, fin + intervalo, intervalo, 1));
            }
        }
        else
        {
            cout << "SI\n";
            return true;
        }
    }

    cout << "NO\n";

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
