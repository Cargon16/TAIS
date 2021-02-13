
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "ConjuntosDisjuntos.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
const std::vector<std::pair<int, int>> dirs = { {1, 0}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {0, 1}, {0, -1}, {-1, -1} };

class ejercicio {
private:
    int max;

public:
    ejercicio(ConjuntosDisjuntos& c, std::vector<string>& m) : max(1) {
        for (int i = 0; i < m.size(); ++i) {
            for (int j = 0; j < m[i].size(); ++j) {
                if (m[i][j] == '#') {
                    unir(c, m, i, j);
                }
            }
        }

        std::cout << max << " ";
    }

    void unir(ConjuntosDisjuntos& c, std::vector<string>& m, int i, int j) {
        for (auto p : dirs) {
            int x = i + p.first, y = j + p.second;
            if (x >= 0 && x < m.size() && y >= 0 && y < m[i].size())
                if (m[x][y] == '#' && !c.unidos(j + m[i].size() * i, (y + m[x].size() * x))) {
                    c.unir((j + m[i].size() * i), (y + m[x].size() * x));
                    int card2 = c.cardinal((j + m[i].size() * i));
                    if (card2 == 14) {
                        int a = 0;
                    }
                    max = std::max(card2, max);
                }
        }
    }

    int getMax() {
        return max;
    }
};

bool resuelveCaso() {
    int F, C;
    // leer los datos de la entrada

    std::cin >> F >> C;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<string> v(F);
    std::cin.ignore();
    for (int i = 0; i < F; ++i) {
        std::getline(std::cin, v[i]);
    }

    ConjuntosDisjuntos c(F * C);
    ejercicio sol(c, v);

    int add, ini, fin;
    std::cin >> add;
    for (int i = 0; i < add; ++i) {
        std::cin >> ini >> fin;
        sol.unir(c, v, ini - 1, fin - 1);
        std::cout << sol.getMax() << " ";
    }
    // resolver el caso posiblemente llamando a otras funciones
    std::cout << "\n";
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
