
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

bool operator < (const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
    return (p1.first < p2.first) || (p1.first == p2.first && p1.second < p2.second);
}

int resolver(PriorityQueue<std::pair<int, int>> &q) {
    int cont = 1;
    std::pair<int, int> x = q.top(); q.pop();
    while (!q.empty()) {
        if (q.top().first >= x.second) {
            cont++;
            x = q.top();
        }
        q.pop();
    }

    return cont;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N;
    // leer los datos de la entrada
    std::cin >> N;
    if (N == 0)
        return false;

    int x, y;
    PriorityQueue<std::pair<int, int>>q;
    for (int i = 0; i < N; ++i) {
        std::cin >> x >> y;
        q.push({x, y});
    }
    std::cout << resolver(q) << "\n";

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
