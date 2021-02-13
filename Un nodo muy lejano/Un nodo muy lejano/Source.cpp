
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
class ejercicio {
private:
    std::vector<bool> visitados;
    std::vector<int> dist;
    int s;
    int visitado;

    void bfs(Grafo const& g, int ttl) {
        std::queue<int> q;
        dist[s] = 0; visitados[s] = true;
        visitado++;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visitados[w]) {
                    if (dist[v] + 1 <= ttl) {
                        dist[w] = dist[v] + 1; visitados[w] = true;
                        visitado++;
                        q.push(w);
                    }
                }
            }
        }
    }
public:
    ejercicio(Grafo& g, int ini, int ttl) : visitados(g.V(), false), visitado(0), dist(g.V(), 0), s(ini) {
        bfs(g, ttl);
        std::cout << g.V() - visitado << "\n";
    }

};

bool resuelveCaso() {
        // leer los datos de la entrada

    Grafo g(std::cin, 1);
    if (!std::cin)  // fin de la entrada
        return false;

    int C, ini, ttl;
    std::cin >> C;
    for (int i = 0; i < C; ++i) {
        std::cin >> ini >> ttl;
        ejercicio sol(g, ini-1, ttl);
    }
    std::cout << "---\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
