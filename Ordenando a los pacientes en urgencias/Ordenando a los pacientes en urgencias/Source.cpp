
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
