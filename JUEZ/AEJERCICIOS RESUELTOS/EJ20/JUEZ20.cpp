#include <iostream>
#include <vector>
#include <queue>
#include "Matriz.h"
#include "Digrafo.h"

using namespace std;

// BFS para encontrar el número mínimo de aristas entre dos vértices
static int bfs_min_aristas(Digrafo const &grafo, int origen, int destino)
{
    vector<int> distancias(grafo.V(), -1);
    queue<int> cola;

    distancias[origen] = 0;
    cola.push(origen);

    while (!cola.empty())
    {
        int verticeActual = cola.front();
        cola.pop();
        if (verticeActual == destino)
            return distancias[verticeActual];

        for (int vecino : grafo.ady(verticeActual))
        {
            if (distancias[vecino] == -1)
            {
                distancias[vecino] = distancias[verticeActual] + 1;
                cola.push(vecino);
            }
        }
    }
    return distancias[destino]; // Por enunciado, siempre alcanzable
}

bool resuelveCaso()
{
    int tamanoTablero, maxDado, numSerpientes, numEscaleras;
    cin >> tamanoTablero >> maxDado >> numSerpientes >> numEscaleras;
    if (!cin)
        return false;
    if (tamanoTablero == 0 && maxDado == 0 && numSerpientes == 0 && numEscaleras == 0)
        return false;

    int numCasillas = tamanoTablero * tamanoTablero; // Total de casillas
    int numVertices = numCasillas;                   // Vértices del grafo: 0..numCasillas-1

    // 1) Construir la numeración real del tablero (serpenteante)
    Matriz<int> numeroCasilla(tamanoTablero, tamanoTablero, 0);
    vector<int> filaDeNodo(numCasillas + 1), columnaDeNodo(numCasillas + 1);

    int numeroActual = 1;
    for (int filaDesdeAbajo = 0; filaDesdeAbajo < tamanoTablero; ++filaDesdeAbajo)
    {
        int fila = tamanoTablero - 1 - filaDesdeAbajo; // Fila real en la matriz (0 arriba)
        if (filaDesdeAbajo % 2 == 0)
        { // Fila desde abajo par: izquierda -> derecha
            for (int columna = 0; columna < tamanoTablero; ++columna)
            {
                numeroCasilla[fila][columna] = numeroActual;
                filaDeNodo[numeroActual] = fila;
                columnaDeNodo[numeroActual] = columna;
                ++numeroActual;
            }
        }
        else
        { // Fila desde abajo impar: derecha -> izquierda
            for (int columna = tamanoTablero - 1; columna >= 0; --columna)
            {
                numeroCasilla[fila][columna] = numeroActual;
                filaDeNodo[numeroActual] = fila;
                columnaDeNodo[numeroActual] = columna;
                ++numeroActual;
            }
        }
    }

    // 2) Procesar serpientes y escaleras
    Matriz<int> destinoSalto(tamanoTablero, tamanoTablero, 0); // Destino del salto (0 si no hay)

    for (int i = 0; i < numSerpientes + numEscaleras; ++i)
    {
        int casillaOrigen, casillaDestino;
        cin >> casillaOrigen >> casillaDestino;
        int fila = filaDeNodo[casillaOrigen], columna = columnaDeNodo[casillaOrigen];
        destinoSalto[fila][columna] = casillaDestino;
    }

    // Construir vector de saltos por casilla
    vector<int> saltoEnCasilla(numCasillas + 1);
    for (int i = 1; i <= numCasillas; ++i)
        saltoEnCasilla[i] = i;

    for (int fila = 0; fila < tamanoTablero; ++fila)
    {
        for (int columna = 0; columna < tamanoTablero; ++columna)
        {
            int casilla = numeroCasilla[fila][columna];
            if (destinoSalto[fila][columna] != 0)
                saltoEnCasilla[casilla] = destinoSalto[fila][columna];
        }
    }

    // 3) Construir el digrafo: una arista = una tirada del dado
    Digrafo grafo(numVertices);

    for (int casillaActual = 1; casillaActual <= numCasillas; ++casillaActual)
    {
        int verticeActual = casillaActual - 1;
        for (int valorDado = 1; valorDado <= maxDado; ++valorDado)
        {
            int casillaDestino = casillaActual + valorDado;
            if (casillaDestino > numCasillas)
                continue;
            casillaDestino = saltoEnCasilla[casillaDestino];
            int verticeDestino = casillaDestino - 1;
            grafo.ponArista(verticeActual, verticeDestino);
        }
    }

    // 4) BFS para mínimo número de tiradas
    int verticeInicio = 0;
    int verticeFin = numCasillas - 1;

    int resultado = bfs_min_aristas(grafo, verticeInicio, verticeFin);
    cout << resultado << "\n";
    return true;
}

int main()
{
    while (resuelveCaso())
        ;
}