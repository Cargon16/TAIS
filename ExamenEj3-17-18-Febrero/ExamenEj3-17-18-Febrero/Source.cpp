
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Matriz.h"

int getMejor(const Matriz<int>& v, int i, int j) {
    int max = 0;
    if (v[i][j - 1] > max) max = v[i][j - 1];
    if (v[i][j] > max) max = v[i][j];
    if (j + 1 < v.numcols() && v[i][j + 1] > max) max = v[i][j + 1];

    return max;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(Matriz<int> &m, int N, int &ind) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            m[i][j] = std::max(m[i - 1][j - 1], std::max(m[i - 1][j], m[i - 1][j + 1])) + m[i][j];
        }
    }

    int total= m[N][0];

    for (int i = 1; i <= N; ++i) {
        if (total < m[N][i]) {
            total = m[N][i];
            ind = i;
        }
    }


    return total;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N;
    // leer los datos de la entrada

    std::cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    Matriz<int> m(N + 1, N + 2, 0);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            std::cin >> m[i][j];
        }
    }
    int ind;
    int total = resolver(m, N, ind);
    std::cout << total << " " << ind << "\n";
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
