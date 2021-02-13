
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

bool resuelveCaso() {
    int N;
    // leer los datos de la entrada

    std::cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<int> ataque(N), defensa(N);
    for (int i = 0; i < N; ++i)
        std::cin >> ataque[i];
    for (int j = 0; j < N; ++j)
        std::cin >> defensa[j];

    sort(ataque.begin(), ataque.end(), std::greater<int>());
    sort(defensa.begin(), defensa.end(), std::greater<int>());

    int exito = 0, x=0, y=0;
    while (x < N && y < N) {
        if (defensa[x] >= ataque[y]) {
            exito++;
            x++;
        }
        y++;
    }

    // resolver el caso posiblemente llamando a otras funciones
    std::cout << exito << "\n";
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
