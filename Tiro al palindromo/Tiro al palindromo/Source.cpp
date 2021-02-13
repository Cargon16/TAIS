
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <string>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(std::string &p, Matriz<int> &m, int i, int j) {
    int &cont = m[i][j];
    if (cont == -1) {
        if (i > j) cont = 0;
        else if (i == j) cont = 1;
        else if (p[i] == p[j]) cont = resolver(p, m, i + 1, j - 1) + 2;
        else {
            cont = std::max(resolver(p, m, i + 1, j), resolver(p, m, i, j - 1));
        }
    }

    return cont;
}

std::string reconstruir(Matriz<int>& m, std::string &p, int i, int j) {
    if (i > j) return {};
    if (i == j) return { p[i] };
    if (p[i] == p[j])
        return p[i] + reconstruir(m, p, i + 1, j - 1) + p[j];
    if (m[i][j] == m[i+1][j])
        return reconstruir(m, p, i+1, j);
    else
        return reconstruir(m, p, i, j-1);
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    std::string p;
    // leer los datos de la entrada

    std::cin >> p;
    if (!std::cin)  // fin de la entrada
        return false;

    Matriz<int> m(p.size(), p.size(), -1);
    int h = resolver(p, m, 0, p.size()-1);
    std::cout << reconstruir(m, p, 0, p.size()-1) << "\n";
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
