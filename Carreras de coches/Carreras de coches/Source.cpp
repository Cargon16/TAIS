
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
    // escribir la soluci�n
    std::cout << cont << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
