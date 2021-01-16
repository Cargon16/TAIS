
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Header.h"

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N, num, P, pos;
    // leer los datos de la entrada

    std::cin >> N;
    if (N==0)
        return false;

    Set<int>a;
    for (int i = 0; i < N; ++i) {
        std::cin >> num;
        a.insert(num);
    }

    std::cin >> P;
    for (int j = 0; j < P; ++j) {
        std::cin >> pos;
        int elem = a.buscaKesimo(pos);
        if (elem == -1) std::cout << "??\n";
        else std::cout << elem << "\n";
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
