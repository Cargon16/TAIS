
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

struct tTarea {
    int ini;
    int fin;
    int periodico;
};

bool operator < (const tTarea &t1, const tTarea &t2) {
    return (t1.ini < t2.ini) || (t1.ini == t2.ini && t1.fin < t2.fin);
}

bool resuelveCaso() {
    int N, M, Min;
    // leer los datos de la entrada

    std::cin >> N >> M >> Min;
    if (!std::cin)  // fin de la entrada
        return false;

    PriorityQueue<tTarea> q;
    int ini, fin, period;
    for (int i = 0; i < N; ++i) {
        std::cin >> ini >> fin;
        q.push({ini, fin, -1});
    }
    for (int i = 0; i < M; ++i) {
        std::cin >> ini >> fin >> period;
        q.push({ ini, fin, period });
    }

    bool solapa = false;
    int j = 0;
    tTarea t = q.top(); q.pop();
    while (!q.empty() && t.ini < Min && !solapa) {
        if (t.fin > q.top().ini && q.top().ini < Min) solapa = true;
        else {
            if (t.periodico != -1)
                q.push({ t.ini + t.periodico, t.fin + t.periodico, t.periodico });
            t = q.top(); q.pop();
        }
    }

    std::cout << (solapa ? "SI\n" : "NO\n");
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
