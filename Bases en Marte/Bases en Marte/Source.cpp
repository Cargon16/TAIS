
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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

struct tBateria {
    int id;
    int capActual;
    int cap;
};
bool operator < (const tBateria &p1, const tBateria& p2) {
    return p1.capActual < p2.capActual || (p1.capActual == p2.capActual && p1.id < p2.id);
}

void resolver(PriorityQueue<tBateria> &q, deque<tBateria> &v, int T, int Z) {
    for (int i = 0; i <= T && !q.empty(); ++i) {
        while (!q.empty() && q.top().capActual == i) {
            tBateria bat = q.top(); q.pop();
                if (bat.cap - Z <= 0) {
                    if (!v.empty()) {
                        tBateria r = v.front(); v.pop_front();
                        q.push({ r.id, r.capActual + i, r.cap});
                    }
                }
                else
                    q.push({bat.id, bat.cap - Z + i, bat.cap - Z });
        }
       
    }
}

bool resuelveCaso() {
    int B, R, Z, T;
    // leer los datos de la entrada

    std::cin >> B;
    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<tBateria>q;
    int cap;
    for (int i = 1; i <= B; ++i) {
        std::cin >> cap;
        q.push({i, cap, cap });
    }

    std::cin >> R;
    deque<tBateria> repuesto;
    for (int i = 1; i <= R; ++i) {
        std::cin >> cap;
        repuesto.push_back({B+i, cap, cap});
    }
    std::cin >> Z >> T;
    // resolver el caso posiblemente llamando a otras funciones
    resolver(q, repuesto, T, Z);
    // escribir la solución
    if (q.size() == 0)
        std::cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";
    else {
        if(q.size() < B)
            std::cout << "FALLO EN EL SISTEMA\n";
        else
            std::cout << "CORRECTO\n";
        while (!q.empty()) {
            std::cout << q.top().id << " " << q.top().capActual << "\n";
            q.pop();
        }
    }
    std::cout << "---\n";
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
