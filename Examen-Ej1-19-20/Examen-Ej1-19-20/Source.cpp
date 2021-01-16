
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(PriorityQueue<int> &c) {
    int gorras = 0;
    while (c.size() > 1) {
        int n1 = c.top(); c.pop();
        int n2 = c.top(); c.pop();

        gorras += n1 + n2;
        c.push(n1+n2);
    }

    return gorras;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N;
    // leer los datos de la entrada
    std::cin >> N;
    if (N == 0)
        return false;

    // escribir sol
    PriorityQueue<int> c;
    int num;
    for (int i = 0; i < N; ++i) {
        std::cin >> num;
        c.push(num);
    }

    std::cout << resolver(c) << "\n";

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
