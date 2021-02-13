
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

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
    std::vector<bool> apilados;
    std::deque<int> orden;
    bool posible;
    void dfs(Digrafo &g, int v) {
        visitados[v] = true;
        apilados[v] = true;
        for (auto w : g.ady(v)) {
            if (!visitados[w]) {
                dfs(g, w);
            }
            else if (apilados[w]) posible = false;
        }

        apilados[v] = false;
        orden.push_front(v);
    }

public:
    ejercicio(Digrafo& g) : visitados(g.V(), false), posible(true), apilados(g.V(), false) {
        for (int i = 0; i < g.V(); ++i) {
            if (!visitados[i])
                dfs(g, i);
        }
    }

    std::deque<int> getOrden() {
        return orden;
    }

    bool getPosible() {
        return posible;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    Digrafo g(std::cin, 1);

    if (!std::cin)  // fin de la entrada
        return false;
    
    ejercicio sol(g);
    deque<int> q = sol.getOrden();
    
    if (!sol.getPosible())
        std::cout << "Imposible";
    else
    while (!q.empty()) {
        std::cout << q.front() + 1 << " ";
        q.pop_front();
    }

    std::cout << "\n";
    // resolver el caso posiblemente llamando a otras funciones

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
