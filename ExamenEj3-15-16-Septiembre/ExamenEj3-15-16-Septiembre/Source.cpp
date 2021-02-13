
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "Matriz.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tJuego {
    int puntos = 0;
    int dardos = 0;
};
const int INF = 1000000000;

std::vector<int> resolver(std::vector<int> &v, int P) {
    Matriz<int> m(v.size(), P + 1, INF);
    int n = v.size() - 1;
    m[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        m[i][0] = 0;
        for (int j = 1; j <= P; ++j) {
            if (j < v[i]) {
                m[i][j] = m[i - 1][j];
            }
            else
            m[i][j] = std::min(m[i - 1][j], m[i][j - v[i]] + 1);
        }
    }

    vector<int> sol;
    if (m[v.size() - 1][P] != INF) {
        if (m[n][P] != INF) {
            int i = n, j = P;
            while (j > 0) { // no se ha pagado todo
                if (v[i] <= j && m[i][j] != m[i - 1][j]) {
                    // tomamos una moneda de tipo i
                    sol.push_back(v[i]); j = j - v[i];
                }
                else // no tomamos más monedas de tipo i
                    --i;
            }
        }

        std::sort(sol.begin(), sol.end());


    }
    return sol;
}
bool resuelveCaso() {
    int P, S;
    // leer los datos de la entrada

    std::cin >> P >> S;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<int> v(S + 1, 0);
    for (int i = 1; i <= S; ++i)
        std::cin >> v[i];
    // resolver el caso posiblemente llamando a otras funciones
    std::vector<int> sol = resolver(v, P);
    
    for (int i = 0; i < sol.size(); ++i) {
        std::cout << sol[i] << " ";
    }
    std::cout << "\n";
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
