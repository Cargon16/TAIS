
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
struct tFestival {
    int grupos;
    int precio;
};

tFestival operator +(const tFestival &f1, const tFestival &f2) {
    tFestival aux;
    aux.grupos = f1.grupos + f2.grupos;
    aux.precio = f1.precio + f2.precio;

    return aux;
}

int resolver(int F, std::vector<tFestival> &v, int P){
    Matriz<int> m(F + 1, P + 1, 0);

    for (int i = 1; i <= F; ++i) {
        for (int j = 1; j <= P; ++j) {
            if (v[i - 1].precio > j)
                m[i][j] = m[i - 1][j];
            else
                m[i][j] = std::max(m[i-1][j], m[i-1][j-v[i-1].precio] + v[i-1].grupos);
        }
    }

    int sol = 0;
    for (int i = 1; i <= P; ++i)
        if (m[F][i] > sol) sol = m[F][i];

    return sol;
}

bool resuelveCaso() {
    int P, F;
    // leer los datos de la entrada

    std::cin >> P >> F;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<tFestival> v(F);
    for (int i = 0; i < F; ++i) {
        std::cin >> v[i].grupos >> v[i].precio;
    }
    // resolver el caso posiblemente llamando a otras funciones
    int sol = resolver(F, v, P);

    // escribir la solución
    std::cout << sol << "\n";

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
