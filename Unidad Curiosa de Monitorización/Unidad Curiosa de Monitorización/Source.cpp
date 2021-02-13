
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

struct tUsuario {
    int id;
    int periodo;
    int periodoAct;
};

bool operator < (const tUsuario& u1, const tUsuario& u2) {
    return (u1.periodoAct < u2.periodoAct) || (u1.periodoAct == u2.periodoAct && u1.id < u2.id);
}

bool resuelveCaso() {
    int U;
    // leer los datos de la entrada

    std::cin >> U;
    if (U == 0)
        return false;
    PriorityQueue<tUsuario> q;
    int id, periodo, consulta;
    for (int i = 0; i < U; ++i) {
        std::cin >> id >> periodo;
        q.push({id, periodo, periodo});
    }

    std::cin >> consulta;
    for (int i = 0; i < consulta; ++i) {
        tUsuario sol = q.top(); q.pop();
        std::cout << sol.id << "\n";
        q.push({sol.id, sol.periodo, sol.periodoAct + sol.periodo});
    }

    std::cout << "---\n";
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
