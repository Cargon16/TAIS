
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
    int E;
    // leer los datos de la entrada

    std::cin >> E;
    if (E == 0)
        return false;


    // resolver el caso posiblemente llamando a otras funciones
    long long int gorras = 0, aux;
    PriorityQueue<long long int> q;
    for (int i = 0; i < E; ++i) {
        std::cin >> aux;
        q.push(aux);
    }
    long long int eq2, eq1 = q.top(); q.pop();
    while (!q.empty()) {
        eq2 = q.top(); q.pop();
        gorras += eq1 + eq2;
        q.push(eq1+eq2);
        eq1 = q.top(); q.pop();
    }
    
    // escribir la soluci�n
    std::cout << gorras << "\n";

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
