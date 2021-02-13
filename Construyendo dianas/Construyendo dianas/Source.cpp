
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "Matriz.h"
#include <algorithm>
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

const int INF = 1000000000;

int resolver(Matriz<int> &m, std::vector<int> &v, int P, int S) {
    m[0][0] = 0;
    for (int i = 1; i <= S; ++i) {
        m[i][0] = 0;
        for (int j = 1; j <= P; ++j) {
            if (v[i] > j) {
                m[i][j] = m[i - 1][j];
            }
            else {
                m[i][j] = std::min(m[i-1][j], m[i][j-v[i]] + 1);
            }
        }
    }

    return m[S][P];
}

bool resuelveCaso() {
    int P, S;
    // leer los datos de la entrada

    std::cin >> P >> S;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<int> v(S+1, 0);
    for (int i = 1; i <= S; ++i)
        std::cin >> v[i];

    // resolver el caso posiblemente llamando a otras funciones
    Matriz<int> m(S + 1, P + 1, INF);
    int num = resolver(m, v, P, S);
    if (num >= INF)
        std::cout << "Imposible";
    else {
        std::cout << num << ":";
        int n = S;
        std::vector<int> cuantas(n + 1, 0);
        int i = n, j = P;
        while (j > 0 && i >0) {
            if (v[i] <= j && (m[i][j] != m[i - 1][j] || (m[i][j-v[i]] + 1 == m[i-1][j] ))) {
                ++cuantas[i];
                j = j - v[i];

            }
            else
                --i;
        }

        std::sort(v.begin(), v.end());

        for (int i = S; i > 0; i--) {
            for (int j = cuantas[i]; j > 0; j--) {
                std::cout << " " << v[i];
            }
        }
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
