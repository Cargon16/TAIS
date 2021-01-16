
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

struct tTarea {
    int ini;
    int fin;
    int periodo = -1;
};

bool operator < (const tTarea &t1, const tTarea &t2) {
    return t1.ini < t2.ini || (t1.ini == t2.ini && t2.fin < t1.fin);
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
bool resolver(PriorityQueue<tTarea> &t, int T) {
    bool solapa = false;
    while (t.size() > 1 && t.top().ini < T && !solapa) {
        tTarea aux = t.top();
        t.pop();
        if (aux.fin > t.top().ini && t.top().ini < T) solapa = true;
        else {
            if (aux.periodo != -1)
                t.push({ aux.ini + aux.periodo, aux.fin + aux.periodo, aux.periodo });
        }

    }

    return solapa;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N, M, T;
    // leer los datos de la entrada
    std::cin >> N >> M >> T;
    if (!std::cin)  // fin de la entrada
        return false;

    int ini, fin, period;
    PriorityQueue<tTarea> c;
    for (int i = 0; i < N; ++i) {
        std::cin >> ini >> fin;
        c.push({ ini, fin });
    }
    for (int i = 0; i < M; ++i) {
        std::cin >> ini >> fin >> period;
        c.push({ ini, fin, period });
    }

    std::cout << (resolver(c, T) ? "SI\n" : "NO\n");

    return true;
}

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
