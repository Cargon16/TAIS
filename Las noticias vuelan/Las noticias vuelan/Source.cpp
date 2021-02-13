
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

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
    std::vector<int> queComp;
    std::vector<int>componentes;
    int compConexa;

    int dfs(Grafo &g, int v) {
        visitados[v] = true;
        queComp[v] = compConexa;
        int tam = 1;
        for (auto w : g.ady(v)) {
            if (!visitados[w]) {
                tam += dfs(g, w);
            }
        }

        return tam;

    }

public:
    ejercicio(Grafo &g) : visitados(g.V(), false), compConexa(0), queComp(g.V()){
        for (int i = 0; i < g.V(); ++i) {
            if (!visitados[i]) {
                int sol = dfs(g, i);
                componentes.push_back(sol);
                compConexa++;
            }
        }
    }

    void solucion(int v) {
        for (int i = 0; i < v; ++i){
            std::cout << componentes[queComp[i]] << " ";
        }
        std::cout << "\n";
    }

};

bool resuelveCaso() {
    int N, M;
    // leer los datos de la entrada

    std::cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g(N);
    int tg, a, b;
    for (int i = 0; i < M; ++i) {
        std::cin >> tg;
        if (tg > 0) std::cin >> a;
        for (int j = 1; j < tg; ++j) {
            std::cin >> b;
            g.ponArista(a-1, b-1);
            a = b;

        }
    }

    ejercicio sol(g);
    sol.solucion(g.V());

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
