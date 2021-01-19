
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Grafo.h"
#include <vector>

class recorreProfundidad {
private:
    std::vector<bool> visitados;
    std::vector<int> queComponente;
    std::vector<int> tamComponente;
    int conexa;

    int dfs(const Grafo& g, int v) {
        int tam = 1;
        visitados[v] = true;
        for (auto w : g.ady(v)) {
            if (!visitados[w]) {
                queComponente[w] = conexa;
                tam += dfs(g, w);
            }
        }
        return tam;
    }

public:
    recorreProfundidad(const Grafo& g) : visitados(g.V(), false), queComponente(g.V()), conexa(0) {
        for (int i = 0; i < g.V(); ++i) {
            if (!visitados[i]) {
                int tam = dfs(g, i);
                tamComponente.push_back(tam);
                conexa++;
                std::cout << tam << " ";
            }
            else
                std::cout << tamComponente[queComponente[i]] << " ";
        }
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int usu, gr;
    // leer los datos de la entrada

    std::cin >> usu >> gr;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g(usu);
    for (int i = 0; i < gr; ++i) {
        int numUsu, v, w;
        std::cin >> numUsu;
        
        if (numUsu != 0) {
            std::cin >> v;
            for (int j = 1; j < numUsu; ++j) {
                std::cin >> w;
                g.ponArista(v - 1, w - 1);
                v = w;
            }
        }
        
    }

    recorreProfundidad p(g);
    std::cout << "\n";
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
