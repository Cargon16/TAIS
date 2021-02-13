
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(std::vector<int> &v) {
    int cont = 0;
    if (v.size() > 2) {
        for (int i = 2; i < v.size(); i = i + 3) {
            cont += v[i];
        }
    }

    return cont;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int L;
    // leer los datos de la entrada
    std::cin >> L;
    if (!std::cin)  // fin de la entrada
        return false;
    
    std::vector<int> v(L);
    for (int i = 0; i < L; ++i) {
        std::cin >> v[i];
    }
    sort(v.begin(), v.end(), std::greater<int>());

    std::cout << resolver(v) << "\n";
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
