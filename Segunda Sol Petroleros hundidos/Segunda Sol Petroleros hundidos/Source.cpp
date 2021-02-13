
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "ConjuntosDisjuntos.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

const std::vector<std::pair<int, int>> pos = { {0, -1}, {0, 1}, {1, 0}, {1, -1}, {1, 1}, {-1, 0}, {-1, -1}, {-1, 1} };

void unirDiagonales(std::vector<std::string>& m, ConjuntosDisjuntos &cjt, int i, int j) {
    for (auto p : pos) {
        int x = i + p.first, y = j + p.second;
        if (x >= 0 && x < m.size() && y >= 0 && y < m[0].size() && m[x][y] == '#' && cjt.buscar((i * m[0].size()) + j) != cjt.buscar((x * m[0].size()) + y)) {
            cjt.unir(((i * m[0].size()) + j), (x * m[0].size()) + y);
        }
    }
}

int resolver(std::vector<std::string> &m, int F, int C, ConjuntosDisjuntos& cjt){
    int max = 1;
    for (int i = 0; i < F; ++i) {
        for (int j = 0; j < C; ++j) {
            if (m[i][j] == '#') {
                unirDiagonales(m, cjt, i, j);
                max = std::max(max, cjt.cardinal((i * m[0].size()) + j));
            }
        }
    }

    return max;
}


bool resuelveCaso() {
    int F, C, N;
    // leer los datos de la entrada

    std::cin >> F >> C;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<std::string> m(F);
    ConjuntosDisjuntos cjt(F*C);
    cin.ignore();
    for (int i = 0; i < F; ++i) {
        std::getline(std::cin, m[i]);
    }

    int max = resolver(m, F, C, cjt);
    std::cout << max << " ";

    int x, y;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> x >> y;
        unirDiagonales(m, cjt, x-1, y-1);
        max = std::max(max, cjt.cardinal((--x * m[0].size()) + --y));
        std::cout << max << " ";
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
