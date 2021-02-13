
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
#include <algorithm>


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(int max, std::vector<int> &v) {
    int i = 0, fin = v.size() - 1, cont = 0;

    while (i < fin) {
        if (v[i] + v[fin] <= max) ++i;
        fin--;
        cont++;
    }

    if (i == fin) cont++;

    return cont;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int M, P;


    std::cin >> M >> P;
    // leer los datos de la entrada
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<int>v(P);
    int p;
    for (int i = 0; i < P; ++i) {
        std::cin >> v[i];
    }
    sort(v.begin(), v.end());
    // escribir sol
    std::cout << resolver(M, v) << "\n";


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
