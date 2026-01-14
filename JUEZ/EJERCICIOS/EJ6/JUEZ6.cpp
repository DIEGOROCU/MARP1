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

 La idea es usar una PriorityQueue de tuplas (gravedad, ordenLlegada, nombrePaciente) para ir añadiendo los pacientes que llegan, manteniendo el orden de prioridad según la gravedad (a mayor gravedad, mayor prioridad, por lo que a menor -gravedad, mayor prioridad) y en caso de empate, según el orden de llegada (a menor ordenLlegada, mayor prioridad), el cual se guarda usando el indice del bucle for que lee los eventos, es decir, un paciente llega antes si su evento "I" aparece antes en la secuencia de eventos.
 El coste de la secuencia de eventos es en caso peor O(n log n), siendo n el número de eventos, ya que cada inserción o extracción de la PriorityQueue cuesta O(log k), siendo k el número de elementos en la cola en ese momento, y en el caso peor k puede llegar a ser n si todos los eventos son inserciones.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso()
{

    // leer los datos de la entrada

    int eventos;
    cin >> eventos;

    if (eventos == 0)
        return false;

    else
    {

        PriorityQueue<tuple<int, int, string>, less<tuple<int, int, string>>> pq;
        for (int i = 0; i < eventos; ++i)
        {
            char tipoEvento;
            cin >> tipoEvento;
            if (tipoEvento == 'I')
            {
                string nombre;
                int gravedad;
                cin >> nombre >> gravedad;
                gravedad = -gravedad; // para que las más graves tengan mayor prioridad
                pq.push(make_tuple(gravedad, i, nombre));
            }
            if (tipoEvento == 'A') {
                auto paciente = pq.top();
                pq.pop();
                cout << get<2>(paciente) << "\n";
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
