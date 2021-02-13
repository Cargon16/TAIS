
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
class libre {
private:
    std::vector<bool> visitados;
    std::vector<int> anterior;
    int visitado;
    bool ciclico;

    void dfs(Grafo &g, int v) {
        visitados[v] = true;
        visitado++;
        for (auto w : g.ady(v)) {
            if (!visitados[w]) {
                anterior[w] = v;
                dfs(g, w);
            }
            else
                if (anterior[v] != w)
                    ciclico = true;
        }
    }
public:
    libre(Grafo& g) : visitados(g.V(), false), visitado(0), ciclico(false), anterior(g.V()) {
        dfs(g, 0);
    }

    bool esLibre() {
        return (visitado == visitados.size() && !ciclico);
    }
};


bool resuelveCaso() {

    // leer los datos de la entrada
    Grafo g(std::cin);
    if (!std::cin)  // fin de la entrada
        return false;

    libre sol(g);
    // resolver el caso posiblemente llamando a otras funciones
    std::cout << (sol.esLibre() ? "SI\n" : "NO\n");
    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
