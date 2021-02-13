
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
using Matriz = std::vector<string>;
const std::vector<std::pair<int, int>> dir = { {1, 0}, {0, -1}, {0, 1}, {-1, 0}};

class ejercicio {
private:
    std::vector<bool> visitados;
    int maxComp;
    int comp;

    int dfs(Matriz& m, int i, int j) {
        visitados[j + (m[i].size() * i)] = true;
        int tam = 1;
        for (auto w : dir) {
            int x = i + w.first, y = j + w.second;
            if(x >=0 && x < m.size() && y >=0 && y < m[x].size())
                if (m[x][y] == '#' && !visitados[y + m[x].size() * x]) {
                    tam += dfs(m, x, y);
                }
        }
        return tam;
    }

public:
    ejercicio(Matriz& m) : visitados(m.size()* m[0].size(), false), maxComp(0) {
        int comp = 0;
        for (int i = 0; i < m.size(); ++i) {
            for (int j = 0; j < m[i].size(); ++j){
                if (m[i][j] == '#' && !visitados[j + (m[i].size() * i)]) {
                    int sol = dfs(m, i, j);
                    maxComp = std::max(sol, maxComp);
                    comp++;
                }
            }
        }

        std::cout << comp << " " << maxComp << "\n";
    }

};

bool resuelveCaso() {
    int F, C;
    // leer los datos de la entrada

    std::cin >> F >> C;
    if (!std::cin)  // fin de la entrada
        return false;

    Matriz m(F);
    // resolver el caso posiblemente llamando a otras funciones
    for (int i = 0; i < m.size(); ++i) {
            std::cin >> m[i];
    }
    ejercicio sol(m);
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
