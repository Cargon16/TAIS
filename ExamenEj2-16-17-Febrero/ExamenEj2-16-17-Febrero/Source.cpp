
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"
#include "Matriz.h"
#include <vector>
#include "TreeSet_AVL.h"

const std::vector<std::pair<int, int>> pos{ {-1, 0}, {0, 1}, {0, -1}, {1, 0} };


void alrededor(Matriz<int>& m, ConjuntosDisjuntos& c, int i, int j, int &max, Set<int> &s) {
    for (auto p : pos) {
        int x = i + p.first, y = j + p.second;
        if(x >=0 && x < m.numfils() && y >=0 && y < m.numcols())
            if(m[x][y] == 0)
                if (c.buscar((i * m.numcols()) + j) != c.buscar((x * m.numcols()) + y)) {
                    c.unir((i * m.numcols()) + j, (x * m.numcols()) + y);
                    int jeje = c.cardinal((x * m.numcols()) + y);
                    max = std::max(max, jeje);
                    if (!s.contains((x * m.numcols()) + y)) {
                        s.insert((x * m.numcols()) + y);
                    }
                }
    }
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
std::pair<int, int> resolver(Matriz<int> &m, ConjuntosDisjuntos &c) {
    int max = 1;
    Set<int> s;
    for (int i = 0; i < m.numfils(); ++i) {
        for (int j = 0; j < m.numcols(); ++j) {
            if (m[i][j] == 0) {
                alrededor(m, c, i, j, max, s);
            }
        }
    }

    Set<int> aux;
    for (auto i = s.begin(); i != s.end(); ++i) {
        if (!aux.contains(c.buscar(*i)))
            aux.insert(*i);
    }

    return {aux.size(), max};
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int C, F;
    char x;
    // leer los datos de la entrada
    std::cin >> F >> C;
    if (!std::cin)  // fin de la entrada
        return false;

    ConjuntosDisjuntos c(F*C);
    Matriz<int> m(F, C, -1);
    for (int i = 0; i < F; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> x;
            if (x == '#') {
                m[i][j] = 0;
            }
        }
    }
    std::pair<int, int> sol = resolver(m, c);
    std::cout << sol.first << " " << sol.second << "\n";
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
