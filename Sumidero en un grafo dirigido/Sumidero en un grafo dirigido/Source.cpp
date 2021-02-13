
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#include "Digrafo.h"  // propios o los de las estructuras de datos de clase

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
    std::vector<int> grado;
    int sumidero;

    void dfs(Digrafo &g, int v) {
        visitados[v] = true;
        for (auto w : g.ady(v)) {
            if (!visitados[w]) {
                dfs(g, w);
            }
            grado[w]++;
            if (grado[w] == g.V() - 1) sumidero = w;
        }
    }

public:
    ejercicio(Digrafo &g): visitados(g.V(), false), sumidero(-1), grado(g.V(), 0){
        for(int i =0; i < g.V(); ++i )
            if(!visitados[i])
                dfs(g, i);
    }

    int getSumidero(){
        return sumidero;
    }
};


bool resuelveCaso() {

    // leer los datos de la entrada
    Digrafo g(std::cin);

    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    ejercicio sol(g);
    int sumidero = sol.getSumidero();
    if (sumidero == -1 && g.V() > 1)
        std::cout << "NO\n";
    else
        std::cout << "SI " << ((g.V() == 1)?0:sumidero) << "\n";
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
