
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Grafo.h"

class recorridoProfundidad {
private:
    std::vector<bool> visitados;
    int maxComp;

    int dfs(const Grafo& g, int v) {
        visitados[v] = true;
        int max = 1;
        for (auto w : g.ady(v)) {
            if (!visitados[w]) {
                max += dfs(g, w);
            }
        }
        return max;
    }

public:
    recorridoProfundidad(const Grafo& g) : visitados(g.V(), false), maxComp(0) {
        for (int i = 0; i < g.V(); ++i) {
            if (!visitados[i]) {
                int comp = dfs(g, i);
                maxComp = std::max(maxComp, comp);
            }
        }
    }

    int getMaxComp() {
        return maxComp;
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    Grafo g(std::cin, 1);
    // leer los datos de la entrada

    recorridoProfundidad sol(g);
    std::cout << sol.getMaxComp() << "\n";
    // escribir sol

}

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
