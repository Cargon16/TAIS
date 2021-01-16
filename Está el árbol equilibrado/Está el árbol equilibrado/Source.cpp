
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(const bintree<char> &a) {
    int izq=0, der=0;
    if (a.empty()) return 1;
    if (a.left().empty() && a.right().empty()) {
        return 1;
    }
    else {
        if (!a.left().empty())
            izq = resolver(a.left());
        if (!a.right().empty())
            der = resolver(a.right());

        if ((izq != -1 || der != -1) || abs(izq - der) > 1) return -1;
        else
            return std::max(izq, der) + 1;
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    bintree<char> a = leerArbol('.');
    int h = resolver(a);
    if (h == -1) std::cout << "NO\n";
    else std::cout << "SI\n";

    // escribir solución
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
