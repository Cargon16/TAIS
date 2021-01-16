
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

struct tPaciente {
    std::string nombre;
    int gravedad;
};

bool operator < (const tPaciente& p1, const tPaciente& p2) {
    return p1.gravedad > p2.gravedad;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n;
    // leer los datos de la entrada
    std::cin >> n;
    if (n == 0)
        return false;

    char opt;
    tPaciente p;
    PriorityQueue<tPaciente> c;
    for (int i = 0; i < n; ++i) {
        std::cin >> opt;
        if (opt == 'I') {
            std::cin >> p.nombre >> p.gravedad;
            c.push(p);
        }
        else {
            std::cout << c.top().nombre << " " << "\n";
            c.pop();
        }
    }
    std::cout << "----\n";
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
