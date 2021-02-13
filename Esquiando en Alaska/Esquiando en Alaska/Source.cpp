
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

bool resuelveCaso() {
    int N;
    // leer los datos de la entrada

    std::cin >> N;
    if (N == 0)
        return false;

    std::vector<int> v(N);
    std::vector<int> v2(N);
    for (int i = 0; i < N; ++i)
        std::cin >> v[i];
    for (int i = 0; i < N; ++i)
        std::cin >> v2[i];

    sort(v.begin(), v.end(), std::greater<int>());
    sort(v2.begin(), v2.end(), std::greater<int>());

    int cont = 0;
    for (int i = 0; i < N; ++i) {
        cont += abs(v[i] - v2[i]);
    }
    // resolver el caso posiblemente llamando a otras funciones

    std::cout << cont << "\n";
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
