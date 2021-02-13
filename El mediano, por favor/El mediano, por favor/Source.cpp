
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

bool resuelveCaso() {
    int N;
    // leer los datos de la entrada

    std::cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<int> q1, q2;
    int opt;
    for (int i = 0; i < N; ++i) {
        std::cin >> opt;
        if (opt == 0) {
            if (q1.empty()) std::cout << "ECSA ";
            else {
                int med = (q1.size() + 1) / 2;
                for (int j = 0; j < med - 1; ++j) {
                    q2.push(q1.top());
                    q1.pop();
                }
                std::cout << q1.top() << " ";
                q1.pop();
                while (!q2.empty()) {
                    q1.push(q2.top());
                    q2.pop();
                }
            }
        }
        else
            q1.push(opt);
    }

    // resolver el caso posiblemente llamando a otras funciones

    // escribir la soluci�n
    std::cout << "\n";
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
