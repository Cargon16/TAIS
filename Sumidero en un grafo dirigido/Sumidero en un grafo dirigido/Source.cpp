
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
