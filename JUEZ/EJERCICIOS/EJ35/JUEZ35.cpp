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

struct tPelicula {
    int inicio;
    int fin;
};

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
        vector<tPelicula> datos(n);
        for (int i = 0; i < n; ++i) {
            int horas, minutos, duracion;
            char aux;
            cin >> horas >> aux >> minutos >> duracion;
            datos[i].inicio = horas * 60 + minutos;
            datos[i].fin = datos[i].inicio + duracion;
        }
        sort(datos.begin(), datos.end(), [](tPelicula const& a, tPelicula const& b) {
            if (a.fin != b.fin) return a.fin < b.fin;
            else return a.inicio < b.inicio;
        });
        int contador = 0;
        int ultimoFin = -1;
        for (int i = 0; i < n; ++i) {
            if (datos[i].inicio >= ultimoFin) {
                ++contador;
                ultimoFin = datos[i].fin + 10;
            }
        }
        cout << contador << "\n";
        // escribir la solución

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
