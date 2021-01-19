
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"
#include "Matriz.h"
#include "TreeSet_AVL.h"

const std::vector<std::pair<int, int>> pos{ {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

void comprobarAdyacentes(const Matriz<int>& m, int i, int j, ConjuntosDisjuntos &c, Set<int> &a) {
    bool tiene = false;
    for (auto p : pos) {
        if(i + p.first >=0 && i + p.first < m.numfils() && j + p.second >=0 && j + p.second < m.numcols())
            if (m[i + p.first][j + p.second] == 0) {
                if (c.buscar((i * m.numcols()) + j) != c.buscar(((i + p.first) * m.numcols()) + (j + p.second))) {
                    c.unir(((i + p.first) * m.numcols()) + (j + p.second), (i * m.numcols()) + j);
                    int b = (c.buscar(((i + p.first) * m.numcols()) + (j + p.second)));
                    if (!a.contains(b)) {
                        a.insert(b);
                    }
                }
            }
    }
}


int resolver(const Matriz<int>& m, ConjuntosDisjuntos& c) {
    Set<int> a;
    int cont = 0;
    for (int i = 0; i < m.numfils(); ++i) {
        for (int j = 0; j < m.numcols(); ++j) {
            if (m[i][j] == 0) {
                comprobarAdyacentes(m, i, j, c, a);
            }
        }
    }
    
    Set<int> b;
    for (auto aux = a.begin(); aux != a.end(); ++aux) {
        int x = c.buscar(*aux);
        if (!b.contains(x)) {
            b.insert(x);
            if (c.cardinal(x) == 22) cont++;
        }
    }
    
    

    return cont;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int F, C;
    // leer los datos de la entrada
    std::cin >> C >> F;
    if (!std::cin)  // fin de la entrada
        return false;

    Matriz<int>m(F, C, -1);
    ConjuntosDisjuntos c(F*C);
    char aux;
    for (int i = 0; i < F; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> aux;
            if (aux == 'X')
                m[i][j] = 0;
        }
    }

    std::cout << resolver(m, c) << "\n";

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
