
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Matriz.h"


const int INF = 1000000000;
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(const Matriz<int>& aux, int N, int ini) {
    Matriz<int> m(N + 1, N + 1, INF);
    m[ini - 1][ini] = 0;
    for (int i = ini; i <= N; ++i) {
        m[i][i] = 0;
        for (int j = i + 1; j <=N; ++j) {
            int res = m[i - 1][i] + aux[i - 1][j - i - 1];
            m[i][j] = std::min(res, m[i - 1][j]);
        }
    }

    for (int i = ini; i < N; ++i) {
        std::cout << m[i][i+1] << " ";
    }
    std::cout << "\n";
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N;
    // leer los datos de la entrada
    std::cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    Matriz<int> m(N, N, 0), aux(N-1, 0, 0);
    int coste;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            std::cin >> coste;
            aux[i].push_back(coste);
        }
    }
    
    for (int i = 1; i < m.numfils(); ++i) {
        resolver(aux, N, i);
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
