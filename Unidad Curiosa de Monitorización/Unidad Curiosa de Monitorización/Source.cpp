
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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

    // escribir la soluci�n

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
