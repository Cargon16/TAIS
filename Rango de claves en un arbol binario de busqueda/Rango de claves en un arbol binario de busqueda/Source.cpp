
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "Header.h"
#include <vector>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(const Set<int> &a, int k1, int k2, std::vector<int> &v, Set<int>::const_iterator it) {
    if (it != a.end()) {
       if(*it >= k1 && *it <= k2)
        v.push_back(*it);
        resolver(a, k1, k2, v, ++it);     
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N, num;

    std::cin >> N;
    // leer los datos de la entrada

    if (N==0)
        return false;
    Set<int> a;
    std::vector<int> v;
    for (int i = 0; i < N; ++i) {
        std::cin >> num;
        a.insert(num);
    }
    int k1, k2;
    std::cin >> k1 >> k2;
    resolver(a, k1, k2, v, a.begin());
    for (auto it = v.cbegin(); it != v.cend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

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
