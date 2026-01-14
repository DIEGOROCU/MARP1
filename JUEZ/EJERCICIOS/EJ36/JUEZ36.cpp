#include <iostream>
using namespace std;

bool resuelveCaso() {
    long long int cantidad, suma;
    if (!(cin >> cantidad >> suma)) return false;

    long long int mitad = suma / 2;
    long long int resultado;

    if (cantidad <= mitad) {
        // Todos los numeros estan en el rango [1, mitad]
        resultado = cantidad * (cantidad + 1) / 2;
    }
    else {
        // Algunos numeros estan en [mitad+1, suma] comenzando desde suma
        long long int exceso = cantidad - mitad;
        long long int sumaMenores = mitad * (mitad + 1) / 2;                 // 1..mitad
        long long int sumaMultiplos = exceso * (2 * suma + exceso - 1) / 2;  // suma..suma+exceso-1
        resultado = sumaMenores + sumaMultiplos;
    }

    cout << resultado << "\n";
    return true;
}

int main() {
    while (resuelveCaso());
}