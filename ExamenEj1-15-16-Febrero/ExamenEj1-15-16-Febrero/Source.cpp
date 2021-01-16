
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

struct tUsuario {
    int id;
    int periodo;
    int periodoAct;
};

bool operator < (const tUsuario& u1, const tUsuario& u2) {
    return u1.periodoAct < u2.periodoAct || (u1.periodoAct == u2.periodoAct && u1.id < u2.id);
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(PriorityQueue<tUsuario> &c, int k) {
    for (int i = 0; i < k; ++i) {
        tUsuario u = c.top(); c.pop();
        std::cout << u.id << "\n";
        c.push({u.id, u.periodo, u.periodoAct+u.periodo});
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int usu;
    // leer los datos de la entrada
    std::cin >> usu;
    if (usu == 0)
        return false;

    PriorityQueue<tUsuario> c;
    int id, period, k;
    std::string palabra;
    for (int i = 0; i < usu; ++i) {
        std::cin >> palabra >> id >> period;
        c.push({id, period, period});
    }
    std::cin >> k;
    resolver(c, k);
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
