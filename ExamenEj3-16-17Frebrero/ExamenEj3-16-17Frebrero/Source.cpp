
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <string>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(const std::string &p1, const std::string &p2) {
    Matriz<int> m(p1.size() + 1, p2.size() + 1, 0);

    for (int i = 1; i <= p1.size(); ++i) {
        for (int j = 1; j <= p2.size(); ++j) {
            if (p1[i - 1] == p2[j - 1]) m[i][j] = m[i-1][j-1] + 1;
            else {
                m[i][j] = std::max(m[i - 1][j], m[i][j - 1]);
            }
        }
    }

    return m[p1.size()][p2.size()];
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string p1, p2;
    // leer los datos de la entrada
    std::cin >> p1 >> p2;
    if (!std::cin)  // fin de la entrada
        return false;


    std::cout << resolver(p1, p2) << "\n";

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
