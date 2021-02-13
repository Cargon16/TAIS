
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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

    // escribir la soluci�n
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
