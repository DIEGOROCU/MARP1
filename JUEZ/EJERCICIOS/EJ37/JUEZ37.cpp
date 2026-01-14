#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool resuelveCaso() {
    int numEdificios;
    if (!(cin >> numEdificios)) return false;
    if (numEdificios == 0) return false; // caso final

    vector<pair<long long, long long>> intervalos; // [inicio, fin] = [W, E-1]
    intervalos.reserve(numEdificios);

    for (int i = 0; i < numEdificios; ++i) {
        long long inicio, fin;
        cin >> inicio >> fin;
        long long izq = inicio;
        long long der = fin - 1;      // inicio posible del tunel
        intervalos.push_back({izq, der});
    }

    sort(intervalos.begin(), intervalos.end(), [](auto const& a, auto const& b) {
        if (a.second != b.second) return a.second < b.second; // por derecha
        return a.first < b.first;                              // desempate por izquierda
    });

    long long ultimoTunel = LLONG_MIN; // ultimo inicio de tunel elegido
    long long tuneles = 0;

    for (auto const& [izq, der] : intervalos) {
        if (ultimoTunel < izq) {      // no esta cubierto el edificio actual
            tuneles++;
            ultimoTunel = der;        // ponemos el tunel lo mas a la derecha posible
        }
        // si izq <= ultimoTunel <= der, ya queda cubierto con el tunel actual
    }

    cout << tuneles << "\n";
    return true;
}

int main() {
    while (resuelveCaso());
}