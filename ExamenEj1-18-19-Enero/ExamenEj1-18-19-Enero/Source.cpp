
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"
#include <vector>
#include <queue>

class recorridoAnchura {
    std::vector<bool> visitados;
    std::vector<int> distancia;

    void bfs(const GrafoValorado<int> &g, int v) {
        std::queue<int> q;
        distancia[v] = 0;
        visitados[v] = true;
        q.push(v);
        while (!q.empty()) {
            int vert = q.front();
            q.pop();
            for (auto w : g.ady(vert)) {
                int x = w.uno();
                int y = w.otro(x);
                if (!visitados[y]) {
                    distancia[y] = distancia[v] + 1;
                    visitados[y] = true;
                    q.push(y);
                }
            }

        }
    }
};

class kruskal {
    void Dijkstra(GrafoValorado<int> g, int s) {
        distToDij[s] = { 0, 0 };
        pq.push(s, { 0,0 });

        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (AristaDirigida<int> e : g.ady(v)) {
                relax(e);
            }
        }
    }

    void relax(AristaDirigida<int> e) {
        int v = e.desde(), w = e.hasta();
        if (distToDij[w].first > distToDij[v].first + e.valor()) {
            distToDij[w].first = distToDij[v].first + e.valor();
            distToDij[w].second = distToDij[v].second + 1;
            edgeTo[w] = e;
            pq.update(w, distToDij[w]);
        }
        else if (distToDij[w].first == distToDij[v].first + e.valor() && distToDij[w].second > distToDij[v].second + 1) {
            distToDij[w].second = distToDij[v].second + 1;
            edgeTo[w] = e;
            pq.update(w, distToDij[w]);
        }
    }

    void aristasDij() {
        aristas = distToDij[_dest].second;
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;

    Solucion sol = resolver(datos);

    // escribir sol

    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
