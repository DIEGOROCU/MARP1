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

#include "bintree.h"

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

tuple<bool, bool, int, int, int> esAVLint(BinTree<int> const& arbol) {
    // Caso base: árbol vacío
    // Devolvemos que claramente es AVL, que no hay valores, y altura 0
    if (arbol.empty()) {
        return {true, false, -1, -1, 0};
    }
    // Caso base: árbol hoja
    // Devolvemos que claramente es AVL, que hay valores (la raiz), y altura 1
    else if (arbol.left().empty() && arbol.right().empty()) {
        return {true, true, arbol.root(), arbol.root(), 1};
    }
    else {
        auto [esAVL_izq, hay_izq, max_izq, min_izq, altura_izq] = esAVLint(arbol.left());
        auto [esAVL_der, hay_der, max_der, min_der, altura_der] = esAVLint(arbol.right());

        int maxi = -1, mini = -1;
        bool maximos = true;
        if (hay_izq && hay_der) {
            maximos = (max_izq < arbol.root() && arbol.root() < min_der);
            maxi = max(max_der, arbol.root());
            mini = min(min_izq, arbol.root());
        }
        else if (hay_izq) {
            maximos = (max_izq < arbol.root());
            maxi = max(max_izq, arbol.root());
            mini = min_izq;
        }
        else if (hay_der) {
            maximos = (arbol.root() < min_der);
            maxi = max_der;
            mini = min(min_der, arbol.root());
        }
        else {
            maximos = true;
            maxi = arbol.root();
            mini = arbol.root();
        }
        bool esAVL = esAVL_izq && esAVL_der && (abs(altura_izq - altura_der) <= 1) && maximos;
        return {esAVL, hay_izq || hay_der || !arbol.empty(), maxi, mini, 1 + max(altura_izq, altura_der)};
    }
}

tuple<bool, bool, string, string, int> esAVLstring(BinTree<string> const& arbol) {
    // Caso base: árbol vacío
    // Devolvemos que claramente es AVL, que no hay valores, y altura 0
    if (arbol.empty()) {
        return {true, false, "", "", 0};
    }
    // Caso base: árbol hoja
    // Devolvemos que claramente es AVL, que hay valores (la raiz), y altura 1
    else if (arbol.left().empty() && arbol.right().empty()) {
        return {true, true, arbol.root(), arbol.root(), 1};
    }
    else {
        auto [esAVL_izq, hay_izq, max_izq, min_izq, altura_izq] = esAVLstring(arbol.left());
        auto [esAVL_der, hay_der, max_der, min_der, altura_der] = esAVLstring(arbol.right());

        string maxi = "", mini = "";
        bool maximos = true;
        if (hay_izq && hay_der) {
            maximos = (max_izq < arbol.root() && arbol.root() < min_der);
            maxi = max(max_der, arbol.root());
            mini = min(min_izq, arbol.root());
        }
        else if (hay_izq) {
            maximos = (max_izq < arbol.root());
            maxi = max(max_izq, arbol.root());
            mini = min_izq;
        }
        else if (hay_der) {
            maximos = (arbol.root() < min_der);
            maxi = max_der;
            mini = min(min_der, arbol.root());
        }
        else {
            maximos = true;
            maxi = arbol.root();
            mini = arbol.root();
        }
        bool esAVL = esAVL_izq && esAVL_der && (abs(altura_izq - altura_der) <= 1) && maximos;
        return {esAVL, hay_izq || hay_der || !arbol.empty(), maxi, mini, 1 + max(altura_izq, altura_der)};
    }
}

bool resuelveCaso()
{

    // leer los datos de la entrada
    char tipo;
    cin >> tipo;

    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones
    bool esAVL_ = false;
    if (tipo == 'N') {
        BinTree<int> arbol = read_tree<int>(cin);
        auto [esAVLres, hay_, max_, min_, altura_] = esAVLint(arbol);
        esAVL_ = esAVLres;
    }
    else {
        BinTree<string> arbol = read_tree<string>(cin);
        auto [esAVLres, hay_, max_, min_, altura_] = esAVLstring(arbol);
        esAVL_ = esAVLres;
    }

    // escribir la solución

    if (esAVL_) cout << "SI\n";
    else cout << "NO\n";

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
