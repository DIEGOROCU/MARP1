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

#include "GrafoValorado.h"
#include "PriorityQueue.h"

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
    int nodos, aristas;
    cin >> nodos;

    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    cin >> aristas;
    GrafoValorado<int> grafo(nodos);
    for (int i = 0; i < aristas; ++i)
    {
        int origen, destino, peso;
        cin >> origen >> destino >> peso;
        grafo.ponArista(Arista<int>(origen - 1, destino - 1, peso));
    }

    // resolver el caso posiblemente llamando a otras funciones

    int consultas;
    cin >> consultas;
    for (int i = 0; i < consultas; ++i)
    {
        int origen, destino;
        cin >> origen >> destino;
        origen--;
        destino--;

        vector<bool> visitados(nodos, false);
        queue<int> q;
        visitados[origen] = true;
        vector<int> padres(nodos, -1);
        vector<pair<int, int>> costes(nodos, {0, 0}); // {coste, numero de aristas}
        q.push(origen);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (auto arista : grafo.ady(v)) {
                int w = arista.otro(v);
                if (!visitados[w]) {
                    visitados[w] = true;
                    padres[w] = v;
                    costes[w] = {costes[v].first + arista.valor(), costes[v].second + 1};
                    q.push(w);
                }
                else if (costes[v].first + arista.valor() < costes[w].first || (costes[v].first + arista.valor() == costes[w].first && costes[v].second + 1 < costes[w].second)) {
                    padres[w] = v;
                    costes[w] = {costes[v].first + arista.valor(), costes[v].second + 1};
                    q.push(w);
                }
            }
        }
        
        // Ahora buscamos solo el camino mas corto
        int costeMin = costes[destino].first;;
        visitados = vector<bool>(nodos, false);
        q = queue<int>();
        visitados[origen] = true;
        padres = vector<int>(nodos, -1);
        q.push(origen);
        vector<int> numeroAristas(nodos, 0); 
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (auto arista : grafo.ady(v)) {
                int w = arista.otro(v);
                if (!visitados[w]) {
                    visitados[w] = true;
                    padres[w] = v;
                    numeroAristas[w] = numeroAristas[v] + 1;
                    q.push(w);
                }
                else if (numeroAristas[v] + 1 < numeroAristas[w]) {
                    padres[w] = v;
                    numeroAristas[w] = numeroAristas[v] + 1;
                    q.push(w);
                }
            }
        }

        if (visitados[destino]) {
            cout << costeMin << " ";
            if (costes[destino].second == numeroAristas[destino]) {
                cout << "SI\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "SIN CAMINO\n";
        }
    }

    // escribir la solución

    cout << "---\n";

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
