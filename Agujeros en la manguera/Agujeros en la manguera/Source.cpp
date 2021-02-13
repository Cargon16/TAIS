
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

bool resuelveCaso() {
    int N, L;
    // leer los datos de la entrada

    std::cin >> N >> L;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i];
    }

    int prim = v[0];
    int cont = 1;

    for (int i = 1; i < v.size(); ++i) {
        if (v[i] - prim > L) {
            cont++;
            prim = v[i];
        }
    }
    // resolver el caso posiblemente llamando a otras funciones

    std::cout << cont << "\n";
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
