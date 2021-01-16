
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
std::vector<int> resolver(PriorityQueue<int, std::greater<int>>&A, PriorityQueue<int, std::greater<int>>&B, int drones) {
    std::vector<int> sol;
    while (!A.empty() && !B.empty()) {
        int res = 0;
        for (int i = 0; i < drones && !A.empty() && !B.empty(); ++i) {
            int a = A.top(); A.pop();
            int b = B.top(); B.pop();
            if (a > b) {
                res += b;
                A.push(a-b);
            }
            if (b > a) {
                res += a;
                B.push(b - a);
            }
            if(b==a)
                res += a;
        }
        sol.push_back(res);
    }

    return sol;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int drones;
    // leer los datos de la entrada

    std::cin >> drones;
    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<int, std::greater<int>> A;
    PriorityQueue<int, std::greater<int>> B;
    
    int a, b, num;
    std::cin >> a >> b;
    for (int i = 0; i < a; ++i) {
        std::cin >> num;
        A.push(num);
    }

    for (int i = 0; i < b; ++i) {
        std::cin >> num;
        B.push(num);
    }

    std::vector<int> sol = resolver(A, B, drones);
    for (int i = 0; i < sol.size(); ++i) {
        std::cout << sol[i] << " ";
    }
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
