
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "GrafoValorado.h"
#include <vector>

class recorreProfundidad {
private:
    std::vector<bool> visitados;

    void dfs(const GrafoValorado<int> &g, int v, int anchura) {
        visitados[v] = true;
        for (auto w : g.ady(v)) {
            int y = w.otro(v);
            if (!visitados[y]) {
                if (w.valor() >= anchura)
                    dfs(g, y, anchura);
            }
        }
    }
public:
    recorreProfundidad(const GrafoValorado<int> &g, int v, int w, int anchura) : visitados(g.V(), false){
        dfs(g, v, anchura);
    }

    bool esPosible(int w){
        return visitados[w];
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    GrafoValorado<int> g(std::cin, 1);
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;

    int casos, v, w, anchura;
    std::cin >> casos;
    
    for (int i = 0; i < casos; ++i) {
        std::cin >> v >> w >> anchura;
        recorreProfundidad p(g, v-1, w-1, anchura);
        std::cout << (p.esPosible(w-1)?"SI":"NO") << "\n";
    }

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
