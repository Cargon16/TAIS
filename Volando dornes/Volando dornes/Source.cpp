
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "PriorityQueue.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {
    int D, M, m;
    // leer los datos de la entrada

    std::cin >> D >> M >> m;
    if (!std::cin)  // fin de la entrada
        return false;

    int b;
    PriorityQueue<int, std::greater<int>> nueve;
    PriorityQueue<int, std::greater<int>> uno;

    for (int i = 0; i < M; ++i) {
        std::cin >> b;
        nueve.push(b);
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> b;
        uno.push(b);
    }

    std::vector<int>horas;
    while (!nueve.empty() && !uno.empty()) {
        int tot = 0;
        std::vector<int> p9, p1;
        for (int i = 0; i < D && (!nueve.empty() && !uno.empty()); ++i) {
            int b1 = nueve.top(); nueve.pop();
            int b2 = uno.top(); uno.pop();
            if (b1 < b2) {
                tot += b1;
                p1.push_back(b2 - b1);
            }
            else{
                tot += b2;
                if(b2 != b1)
                    p9.push_back(b1 - b2);
            }

        }
        for (int i = 0; i < p9.size(); ++i)
            nueve.push(p9[i]);
        for (int i = 0; i < p1.size(); ++i)
            uno.push(p1[i]);

        horas.push_back(tot);
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    for (int i = 0; i < horas.size(); ++i) {
        std::cout << horas[i] << " ";
    }
    std::cout << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
