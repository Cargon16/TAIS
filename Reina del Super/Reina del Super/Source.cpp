
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
struct tCajas {
    int id;
    int tiempo;
};

bool operator < (const tCajas& c1, const tCajas& c2) {
    return (c1.tiempo < c2.tiempo) || (c1.tiempo == c2.tiempo && c1.id < c2.id);
}

bool resuelveCaso() {
    int cajas, clientes;
    // leer los datos de la entrada

    std::cin >> cajas >> clientes;
    if (cajas ==0 && clientes == 0)
        return false;

    PriorityQueue<tCajas> q;
    for (int i = 0; i < cajas; ++i) {
        q.push({i, 0});
    }
    int cl;
    for (int i = 0; i < clientes; ++i) {
        std::cin >> cl;
        tCajas c = q.top(); q.pop();
        q.push({c.id, c.tiempo + cl});
    }

    std::cout << q.top().id + 1 << "\n";
    // resolver el caso posiblemente llamando a otras funciones

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
