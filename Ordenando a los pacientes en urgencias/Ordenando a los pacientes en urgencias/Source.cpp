
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

struct tPaciente {
    std::string nombre;
    int gravedad;
    int turno;
};

bool operator <(const tPaciente& u1, const tPaciente& u2) {
    return (u1.gravedad > u2.gravedad) || (u1.gravedad == u2.gravedad && u1.turno < u2.turno);
}

bool resuelveCaso() {
    int N;
    // leer los datos de la entrada

    std::cin >> N;
    if (N==0)
        return false;

    char e;
    std::string nombre;
    int gravedad;
    PriorityQueue<tPaciente> q;

    for (int i = 0; i < N; ++i) {
        std::cin >> e;
        if (e == 'I') {
            std::cin >> nombre >> gravedad;
            q.push({nombre, gravedad, i});
        }
        else {
            tPaciente p = q.top(); q.pop();
            std::cout << p.nombre << "\n";
        }
    }
    // resolver el caso posiblemente llamando a otras funciones
    std::cout << "---\n";
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
