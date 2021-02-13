
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "GrafoValorado.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class ejercicio {
private:
    std::vector<bool> visitados;

    void dfs(GrafoValorado<int> &g, int v, int camion) {
        visitados[v] = true;
        for (auto w : g.ady(v)) {
            int x = w.otro(v);
            if (!visitados[x] && w.valor() >= camion) {
                dfs(g, x, camion);
            }
        }
    }
public:
    ejercicio(GrafoValorado<int> &g, int v, int camion):visitados(g.V(), false) {
        dfs(g, v, camion);
    }

    bool esPosible(int fin) {
        return visitados[fin];
    }

};

bool resuelveCaso() {
    GrafoValorado<int> g(std::cin, 1);
    // leer los datos de la entrada

    if (!std::cin)  // fin de la entrada
        return false;

    int c, ini, fin, a;
    std::cin >> c;
    for (int i = 0; i < c; ++i) {
        std::cin >> ini >> fin >> a;
        ejercicio sol(g, ini - 1, a);
        std::cout << (sol.esPosible(fin - 1) ? "SI\n" : "NO\n");
    }
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
