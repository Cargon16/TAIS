
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

#include "GrafoValorado.h"  // propios o los de las estructuras de datos de clase
#include "IndexPQ.h"

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Ejercicio {
private:
    std::vector<bool> visit; // visit[v] = ¿hay camino de s a v?
    std::vector<int> ant; // ant[v] = último vértice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s-v más corto
    int s;

    void bfs(GrafoValorado<int> const& g) {
        std::queue<int> q;
        dist[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto w : g.ady(v)) {
                int x = w.otro(v);
                if (!visit[x]) {
                    ant[x] = v; dist[x] = dist[v] + 1; visit[x] = true;
                    q.push(x);
                }
            }
        }
    }


public:
    Ejercicio(GrafoValorado<int> const& g, int s) : visit(g.V(), false), ant(g.V()), dist(g.V()), s(s){
        bfs(g);
    }

    int sol(int w) {
        return dist[w];
    }

    bool haycamino(int w) {
        return visit[w];
    }
    
};

class Dijkstra {
private:
    const int INF = 1000000000;
    int origen;
    std::vector<int> dist;
    std::vector<Arista<int>> ulti;
    std::vector<int> numAristas;
    IndexPQ<int> pq;

    void relajar(Arista<int> a, int v) {
        int w = a.otro(v);
        if (dist[w] > dist[v] + a.valor()) {
            numAristas[w] = numAristas[v] + 1;
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            pq.update(w, dist[w]);
        }
        else if (dist[w] == dist[v] + a.valor() && numAristas[w] > numAristas[v] + 1) {
            numAristas[w] = numAristas[v] + 1;
            ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }

public:
    Dijkstra(GrafoValorado<int> const& g, int orig) : origen(orig), dist(g.V(), INF), ulti(g.V()), pq(g.V()), numAristas(g.V(), 0){
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a, v);
        }
    }

    std::pair<int, int> sol(int w) {
        return { numAristas[w], dist[w]};
    }
};


bool resuelveCaso() {

    // leer los datos de la entrada
    GrafoValorado<int> g(std::cin, 1);
    if (!std::cin)  // fin de la entrada
        return false;

    int K, v, w;

    std::cin >> K;
    for (int i = 0; i < K; ++i) {
        std::cin >> v >> w;

        Ejercicio ej(g, v-1);
        if (ej.haycamino(w-1)) {
            Dijkstra dij(g, v-1);
                    int sol = ej.sol(w-1);
                    std::pair<int, int> sol1 = dij.sol(w-1);

                    if (sol == sol1.first) std::cout << sol1.second << " SI" << "\n";
                    else std::cout << sol1.second << " NO" << "\n";
        }
        else
            std::cout << "SIN CAMINO\n";
        
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
