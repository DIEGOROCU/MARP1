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
    int filas, columnas;
    cin >> filas >> columnas;

    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones
    vector<vector<bool>> matriz(filas, vector<bool>(columnas, false));
    for (int i = 0; i < filas; ++i)
    {
        for (int j = 0; j < columnas; ++j)
        {
            char aux;
            cin >> aux;
            if (aux == '#')
                matriz[i][j] = true;
        }
    }

    // escribir la solución
    int mancha_mas_grande = 0;
    int mancha_actual = 0;
    int cant_manchas = 0;
    vector<vector<bool>> visitado(filas, vector<bool>(columnas, false));
    for (int i = 0; i < filas; ++i)
    {
        for (int j = 0; j < columnas; ++j)
        {
            if (!visitado[i][j]) {
                visitado[i][j] = true;
                if (matriz[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i + 1, j});
                    q.push({i - 1, j});
                    q.push({i, j + 1});
                    q.push({i, j - 1});
                    mancha_actual = 1;
                    while (!q.empty()) {
                        pair<int, int> actual = q.front();
                        q.pop();
                        int fila = actual.first;
                        int columna = actual.second;
                        if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas && !visitado[fila][columna]) {
                            visitado[fila][columna] = true;
                            if (matriz[fila][columna]) {
                                mancha_actual++;
                                q.push({fila + 1, columna});
                                q.push({fila - 1, columna});
                                q.push({fila, columna + 1});
                                q.push({fila, columna - 1});
                            }
                        }
                    }
                    cant_manchas++;
                }
                mancha_mas_grande = max(mancha_mas_grande, mancha_actual);
            }
        }
    }

    cout << cant_manchas << " " << mancha_mas_grande << "\n";

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
