
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

struct tEdificio {
    int ini;
    int fin;
};

bool operator <(const tEdificio& e1, const tEdificio& e2) {
    return (e1.fin < e2.fin);
}

bool resuelveCaso() {
    int N;
    // leer los datos de la entrada

    std::cin >> N;
    if (N == 0)
        return false;


    std::vector<tEdificio> v;
    int ini, fin;
    for (int i = 0; i < N; ++i) {
        std::cin >> ini >> fin;
        v.push_back({ini, fin});
    }

    sort(v.begin(), v.end());
    tEdificio e = v[0];
    int cont = 1;
    for (int i = 1; i < N; ++i) {
        if (v[i].ini >= e.fin) {
            cont++;
            e = v[i];
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
