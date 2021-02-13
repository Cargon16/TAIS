
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
    int max;

    int dfs(Grafo& g, int v) {
        int conexa = 1;
        visitados[v] = true;
        for (auto w : g.ady(v)) {
            if (!visitados[w]) {
                conexa += dfs(g, w);
            }
        }
        return conexa;
    }

public:
    ejercicio(Grafo& g) :visitados(g.V(), false), max(0) {
        for (int i = 0; i < g.V(); ++i) {
            if (!visitados[i]) {
                int sol = dfs(g, i);
                max = std::max(sol, max);
            }
        }
    }

    int getMax() {
        return max;
    }
};

void resuelveCaso() {
    Grafo g(std::cin, 1);
    // leer los datos de la entrada
    ejercicio sol(g);
    std::cout << sol.getMax() << "\n";
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
