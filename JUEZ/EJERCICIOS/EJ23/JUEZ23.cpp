#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Matriz.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

// Convierte coordenadas 2D en indice lineal
static inline int id(int fila, int col, int numCols) { return fila * numCols + col; }

bool resuelveCaso()
{
    int numFilas, numCols;
    if (!(cin >> numFilas >> numCols))
        return false;

    Matriz<char> foto(numFilas, numCols, '-');

    // Estructura DSU externa para unir celdas conectadas
    ConjuntosDisjuntos componentes(numFilas * numCols);

    // Marca que celdas estan activas (tienen petroleo)
    vector<char> activo(numFilas * numCols, false);

    int maxMancha = 0;

    // Vecinos "anteriores" para el estado inicial: arriba-izq, arriba, arriba-der, izquierda
    const int drPrev[4] = {-1, -1, -1, 0};
    const int dcPrev[4] = {-1, 0, 1, -1};

    for (int fila = 0; fila < numFilas; ++fila)
    {
        string linea;
        cin >> linea;
        for (int col = 0; col < numCols; ++col)
        {
            foto[fila][col] = linea[col];
            if (foto[fila][col] == '#')
            {
                int idx = id(fila, col, numCols);
                activo[idx] = true;
                maxMancha = max(maxMancha, 1);

                // Unimos con vecinos ya leidos si tambien tienen petroleo
                for (int k = 0; k < 4; ++k)
                {
                    int nf = fila + drPrev[k], nc = col + dcPrev[k];
                    if (0 <= nf && nf < numFilas && 0 <= nc && nc < numCols)
                    {
                        int vecinoIdx = id(nf, nc, numCols);
                        if (activo[vecinoIdx])
                        {
                            componentes.unir(idx, vecinoIdx);
                        }
                    }
                }
                // El tamano de la mancha puede crecer tras unir
                maxMancha = max(maxMancha, componentes.cardinal(idx));
            }
        }
    }

    int N;
    cin >> N;

    cout << maxMancha;

    // 8 direcciones para las actualizaciones
    const int dr8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dc8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < N; ++i)
    {
        int filaEntrada, colEntrada;
        cin >> filaEntrada >> colEntrada;
        int fila = filaEntrada - 1, col = colEntrada - 1;
        int idx = id(fila, col, numCols);

        // Si ya era petroleo, no cambia nada
        if (!activo[idx])
        {
            activo[idx] = true;
            foto[fila][col] = '#';

            // Unimos con todos los vecinos activos (petroleo) en 8 direcciones
            for (int k = 0; k < 8; ++k)
            {
                int nf = fila + dr8[k], nc = col + dc8[k];
                if (0 <= nf && nf < numFilas && 0 <= nc && nc < numCols)
                {
                    int vecinoIdx = id(nf, nc, numCols);
                    if (activo[vecinoIdx])
                    {
                        componentes.unir(idx, vecinoIdx);
                    }
                }
            }
            maxMancha = max(maxMancha, componentes.cardinal(idx));
        }

        cout << ' ' << maxMancha;
    }

    cout << "\n";
    return true;
}

int main()
{
    while (resuelveCaso())
        ;
}