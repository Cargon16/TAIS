
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;
#include "PriorityQueue.h"
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"

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
    int coste;
    std::vector<Arista<int>> _ARM;
    ConjuntosDisjuntos cjtos;
public:
    ejercicio(GrafoValorado<int> const& g) : coste(0), cjtos(g.V()) {
        PriorityQueue<Arista<int>> pq(g.aristas());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); coste += a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
        }
    }

    int esPosible(int V) {
        return ((cjtos.cardinal(0) == V) ? coste : -1);
    }
};

bool resuelveCaso() {
    GrafoValorado<int> g(std::cin, 1);
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;

    ejercicio sol(g);
    int s = sol.esPosible(g.V());
    if (s != -1)
        std::cout << s;
    else
        std::cout << "No hay puentes suficientes";

    std::cout << "\n";
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
