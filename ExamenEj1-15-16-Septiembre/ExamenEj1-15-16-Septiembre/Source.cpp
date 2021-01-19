
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"
#include <vector>

class kruskal {
private:
    int coste;
    int v;
    std::vector<Arista<int>> _ARM;
public:
    int getCoste() {
        return coste;
    }

    bool esPosible() {
        return _ARM.size() == v-1;
    }

    kruskal(const GrafoValorado<int>& g) :coste(0), v(g.V()) {
        PriorityQueue<Arista<int>> q(g.aristas());
        ConjuntosDisjuntos c(g.V());

        while (!q.empty()) {
            auto a = q.top(); q.pop();
            int v = a.uno(), w = a.otro(v);
            if (!c.unidos(v, w)) {
                c.unir(v, w);
                coste += a.valor();
                _ARM.push_back(a);
                if (_ARM.size() == g.V() - 1) break;
            }
        }
    }

};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    GrafoValorado<int> g(std::cin, 1);
    // leer los datos de la entrada
    if (!std::cin)  // fin de la entrada
        return false;
    
    kruskal k(g);
    
    if (k.esPosible())
        std::cout << k.getCoste() << "\n";
    else
        std::cout << "No hay puentes suficientes\n";

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
