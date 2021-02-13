
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
struct tMusico {
    int numMusicos;
    int atriles;
};

bool operator < (const tMusico &m1, const tMusico &m2) {
    return (((double)m1.numMusicos / (double)m1.atriles) > ((double)m2.numMusicos / (double)m2.atriles));
}

bool resuelveCaso() {
    int p, n;
    // leer los datos de la entrada

    std:cin >> p >> n;
    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<tMusico> q;
    int numMus;
    for (int i = 0; i < n; ++i) {
        std::cin >> numMus;
        q.push({numMus, 1});
    }
    p -= n;
    for (int i = 0; i < p; ++i) {
        tMusico m = q.top(); q.pop();
        m.atriles++;
        q.push(m);
    }
    // resolver el caso posiblemente llamando a otras funciones
    std::cout << (q.top().numMusicos / q.top().atriles) + (q.top().numMusicos % q.top().atriles != 0) << "\n";
    // escribir la solución

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
