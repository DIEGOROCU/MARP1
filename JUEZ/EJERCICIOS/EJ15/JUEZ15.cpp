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

#include "Grafo.h"

using namespace std;

/*@ <answer>

   Solución: Construimos un grafo donde dos usuarios son adyacentes si pertenecen
   al mismo grupo. Luego, para cada usuario, calculamos el tamaño de su componente
   conectada usando BFS.
   
   Coste: O(N + (suma de tamaños de grupos)^2 / M) para construir el grafo + 
          O(N*(N+A)) para calcular componentes = O(N^2)

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

int bfsSize(int start, const Grafo& g, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int size = 0;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        size++;
        
        for (int w : g.ady(v)) {
            if (!visited[w]) {
                visited[w] = true;
                q.push(w);
            }
        }
    }
    
    return size;
}

bool resuelveCaso()
{
    int n, m;
    cin >> n >> m;
    
    if (!cin)
        return false;
    
    Grafo g(n);
    
    // Leer los grupos y conectar usuarios que están en el mismo grupo
    for (int i = 0; i < m; i++) {
        int groupSize;
        cin >> groupSize;
        
        if (groupSize > 0) {
            int firstUser;
            cin >> firstUser;
            firstUser--;
            for (int j = 1; j < groupSize; j++) {
                int otherUser;
                cin >> otherUser;
                otherUser--;
                g.ponArista(firstUser, otherUser);
            }
        }
    }
    
    // Para cada usuario, calcular el tamaño de su componente
    vector<bool> visited(n, false);
    vector<int> componentSize(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int tamanoActual = 1;
            queue<int> q;
            queue<int> estaComponente;
            visited[i] = true;
            estaComponente.push(i);
            for (int w : g.ady(i)) {
                if (!visited[w]) {
                    visited[w] = true;
                    q.push(w);
                }
            }
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                estaComponente.push(v);
                tamanoActual++;
                
                for (int w : g.ady(v)) {
                    if (!visited[w]) {
                        visited[w] = true;
                        q.push(w);
                    }
                }
            }
            while (!estaComponente.empty()) {
                int v = estaComponente.front();
                estaComponente.pop();
                componentSize[v] = tamanoActual;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << componentSize[i] << " ";
    }
    cout << "\n";
    
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
