#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include "Digrafo.h"
#include <functional>

using namespace std;

// BFS para marcar los vertices alcanzables desde el origen
static vector<bool> alcanzables(Digrafo const &g, int origen)
{
    vector<bool> visitado(g.V(), false);
    queue<int> pendientes;
    visitado[origen] = true;
    pendientes.push(origen);

    while (!pendientes.empty())
    {
        int vertice = pendientes.front();
        pendientes.pop();
        for (int vecino : g.ady(vertice))
        {
            if (!visitado[vecino])
            {
                visitado[vecino] = true;
                pendientes.push(vecino);
            }
        }
    }
    return visitado;
}

// Deteccion de ciclo dirigido en la parte alcanzable (ignorando el nodo terminal)
static bool hayCicloAlcanzable(Digrafo const &g, vector<bool> const &alcanzable, int terminal)
{
    vector<int> color(g.V(), 0);
    bool existeCiclo = false;

    function<void(int)> dfs = [&](int vertice)
    {
        color[vertice] = 1; // gris
        for (int vecino : g.ady(vertice))
        {
            if (vecino == terminal)
                continue;
            if (!alcanzable[vecino])
                continue;

            if (color[vecino] == 0)
                dfs(vecino);
            else if (color[vecino] == 1)
                existeCiclo = true;
            if (existeCiclo)
                return;
        }
        color[vertice] = 2; // negro
    };

    // DFS solo desde nodos alcanzables desde la instruccion 1 (vertice 0)
    for (int vertice = 0; vertice < g.V(); ++vertice)
    {
        if (vertice == terminal)
            continue;
        if (alcanzable[vertice] && color[vertice] == 0)
        {
            dfs(vertice);
            if (existeCiclo)
                return true;
        }
    }
    return false;
}

bool resuelveCaso()
{
    int numInstrucciones;
    cin >> numInstrucciones;
    if (!cin)
        return false;

    // Vertices: 0..L-1 (instrucciones 1..L) y L (terminal = "despues de la ultima")
    int terminal = numInstrucciones;
    Digrafo grafo(numInstrucciones + 1);

    for (int i = 1; i <= numInstrucciones; ++i)
    {
        char operacion;
        cin >> operacion;

        int origen = i - 1;                       // instruccion i
        int siguiente = (i == numInstrucciones ? terminal : i); // instruccion i+1 (o terminal si i=L)

        if (operacion == 'A')
        {
            grafo.ponArista(origen, siguiente);
        }
        else if (operacion == 'J')
        {
            int salto;
            cin >> salto;
            grafo.ponArista(origen, salto - 1);
        }
        else if (operacion == 'C')
        {
            int salto;
            cin >> salto;
            grafo.ponArista(origen, salto - 1); // rama salto
            grafo.ponArista(origen, siguiente); // rama "seguir"
        }
    }

    vector<bool> alcanzable = alcanzables(grafo, 0);
    if (!alcanzable[terminal])
    {
        cout << "NUNCA\n";
        return true;
    }

    bool hayCiclo = hayCicloAlcanzable(grafo, alcanzable, terminal);
    if (hayCiclo)
        cout << "A VECES\n";
    else
        cout << "SIEMPRE\n";

    return true;
}

int main()
{
    while (resuelveCaso())
        ;
}