
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
#include <limits>
#include <iostream>
#include <fstream>
#include "bintree_eda.h"

struct tResultado {
    int h = 0;
    int minValor = std::numeric_limits<int>::max();
    int maxValor = -1;
};

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
tResultado resolver(const bintree<int> &a) {
    tResultado izq, der;
    if (a.empty()) return { 1, 1, 1 };
    if (a.left().empty() && a.right().empty()) {
        return { 1, a.root(), a.root()};
    }
    else {
        if (!a.left().empty()) 
            izq = resolver(a.left());
            
        if (!a.right().empty())
            der = resolver(a.right());

        if ((izq.h == -1 || der.h == -1) || abs(izq.h - der.h) > 1 || izq.maxValor >= a.root() || der.minValor <= a.root())
            return { -1, -1, -1 };
        else
            return { std::max(izq.h, der.h) + 1, std::min(izq.minValor, std::min(der.minValor, a.root())), std::max(izq.maxValor, std::max(der.maxValor, a.root())) };
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {

    // leer los datos de la entrada
    bintree<int> a = leerArbol(-1);
    tResultado res = resolver(a);
    if (res.h == -1) std::cout << "NO\n";
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
