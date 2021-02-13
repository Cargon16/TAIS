
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
    int N;
    // leer los datos de la entrada
    std::cin >> N;
    if (N ==0)
        return false;

    PriorityQueue<long long int> q;
    // resolver el caso posiblemente llamando a otras funciones
    int num;
    for (int i = 0; i < N; ++i) {
        std::cin >> num;
        q.push(num);
    }

    long long int x = q.top(), sum = 0;
    q.pop();
    while (!q.empty()) {
        long long int y = q.top(); q.pop();
        sum += (x + y);
        q.push(x+ y);
        x = q.top(); q.pop();
    }

    std::cout << sum << "\n";
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
