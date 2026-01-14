#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Intervalo {
    long long inicio, fin; // [inicio, fin)
};

bool resuelveCaso() {
    long long inicioTotal, finTotal;
    int numIntervalos;
    if (!(cin >> inicioTotal >> finTotal >> numIntervalos)) return false;
    if (inicioTotal == 0 && finTotal == 0 && numIntervalos == 0) return false;

    vector<Intervalo> intervalos;

    for (int i = 0; i < numIntervalos; ++i) {
        long long inicio, fin;
        cin >> inicio >> fin;
        intervalos.push_back({inicio, fin});
    }

    sort(intervalos.begin(), intervalos.end(), [](const Intervalo& a, const Intervalo& b) {
        if (a.inicio != b.inicio) return a.inicio < b.inicio;
        return a.fin > b.fin;
    });

    long long posActual = inicioTotal;
    long long mejorFin = inicioTotal;
    int usados = 0;
    int i = 0;

    while (posActual < finTotal) {
        // Miramos todos los intervalos que empiezan antes o en 'posActual'
        while (i < numIntervalos && intervalos[i].inicio <= posActual) {
            mejorFin = max(mejorFin, intervalos[i].fin);
            i++;
        }
        // Si no hemos podido avanzar, no se puede cubrir
        if (mejorFin <= posActual) {
            cout << "Imposible\n";
            return true;
        }
        usados++;
        posActual = mejorFin; // avanzamos la cobertura
    }

    cout << usados << "\n";
    return true;
}

int main() {
    while (resuelveCaso());
}