
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
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

void resuelveCaso() {
    int B, Min;
    // leer los datos de la entrada

    std::cin >> B >> Min;
    // resolver el caso posiblemente llamando a otras funciones
    std::vector<int> v(B);
    for (int i = 0; i < B; ++i)
        std::cin >> v[i];

    sort(v.begin(), v.end(), std::greater<int>());
    int i = 0, j = v.size() - 1;
    int cont = 0;
    while (i < j) {
        if (v[i] + v[j] >= Min) {
            cont++;
            ++i;
        }
        j--;
    }
    // escribir la solución
    std::cout << cont << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
