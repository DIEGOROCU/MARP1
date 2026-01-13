#include <iostream>
#include <vector>
#include <queue>
#include "Digrafo.h"

using namespace std;

static const int MOD = 10000;

// Construye el digrafo de estados (0..9999) con las 3 operaciones
Digrafo construirGrafo()
{
    Digrafo grafo(MOD);
    for (int estado = 0; estado < MOD; ++estado)
    {
        int siguienteInc = (estado + 1) % MOD;  // Operación +1
        int siguienteDoble = (estado * 2) % MOD; // Operación *2
        int siguienteDiv = estado / 3;           // Operación /3
        grafo.ponArista(estado, siguienteInc);
        grafo.ponArista(estado, siguienteDoble);
        grafo.ponArista(estado, siguienteDiv);
    }
    return grafo;
}

// BFS para encontrar el camino más corto entre dos estados
int bfsMinPulsaciones(Digrafo const &grafo, int estadoInicial, int estadoFinal)
{
    if (estadoInicial == estadoFinal)
        return 0;

    vector<int> distancias(MOD, -1);
    queue<int> cola;

    distancias[estadoInicial] = 0;
    cola.push(estadoInicial);

    while (!cola.empty())
    {
        int estadoActual = cola.front();
        cola.pop();

        int nuevaDistancia = distancias[estadoActual] + 1;

        for (int estadoVecino : grafo.ady(estadoActual))
        {
            if (distancias[estadoVecino] == -1)
            {
                distancias[estadoVecino] = nuevaDistancia;
                if (estadoVecino == estadoFinal)
                    return distancias[estadoVecino]; // Salida temprana al encontrar el destino
                cola.push(estadoVecino);
            }
        }
    }

    return distancias[estadoFinal];
}

bool resuelveCaso(Digrafo const &grafo)
{
    int estadoInicial, estadoFinal;
    if (!(cin >> estadoInicial >> estadoFinal))
        return false; // EOF

    cout << bfsMinPulsaciones(grafo, estadoInicial, estadoFinal) << "\n";
    return true;
}

int main()
{
    Digrafo grafo = construirGrafo();
    while (resuelveCaso(grafo))
    {
    }
}