
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Grafo.h"
#include <vector>

class recorridoProfundidad {
private:
    std::vector<bool>visitados;
    std::vector<int> ant;
    bool ciclo;
    int visita;

    void dfs(const Grafo& g, int v) {
        visitados[v] = true;
        visita++;
        for (int aux : g.ady(v)) {
            if (!visitados[aux]) {
                ant[aux] = v;
                dfs(g, aux);
            }
            else
                if(ant[v] != aux)
                ciclo = true;
        }
    }

public:
    recorridoProfundidad(const Grafo& g, int v) : visitados(g.V(), false), ant(g.V(), -1), ciclo(false), visita(0) {
        dfs(g, v);
    }

    bool getCiclo() {
        return ciclo;
    }
    int getVisita() {
        return visita;
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    Grafo g(std::cin);
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;
    recorridoProfundidad p(g, 0);
    // escribir sol
    if (p.getCiclo() || p.getVisita() != g.V()) std::cout << "NO\n";
    else std::cout << "SI\n";

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
