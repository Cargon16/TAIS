
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "Matriz.h"// propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct tBombilla {
    int coste;
    int potencia;
};

const int INF = 1000000000;

tBombilla resolver(std::vector<tBombilla> &v, int min, int max) {
    Matriz<int> m(v.size() + 1, max + 1, INF);
    m[0][0] = 0;
    for (int i = 1; i <= v.size(); ++i) {
        m[i][0] = 0;
        for (int j = 1; j <= max; ++j) {
            if (v[i-1].potencia > j) {
                m[i][j] = m[i - 1][j];
            }
            else {
                m[i][j] = std::min(m[i - 1][j], m[i][j - v[i-1].potencia] + v[i-1].coste);
            }
               
        }
    }

int costeMin = m[v.size()][min];
int p = min;

for (int i = min; i <= max; i++) {
    if (costeMin > m[v.size()][i]) {
        costeMin = m[v.size()][i];
        p = i;
    }
}

return { costeMin, p };
}

bool resuelveCaso() {
    int B, min, max;
    // leer los datos de la entrada

    std::cin >> B >> max >> min;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<tBombilla> v(B);
    for (int i = 0; i < B; ++i)
        std::cin >> v[i].potencia;
    for (int i = 0; i < B; ++i)
        std::cin >> v[i].coste;

    tBombilla sol = resolver(v, min, max);
    if (sol.potencia > max || sol.coste == INF)
        std::cout << "IMPOSIBLE\n";
    else
        std::cout << sol.coste << " " << sol.potencia << "\n";

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
