
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
struct tTarea {
    int ini;
    int fin;
};

bool operator < (const tTarea &t1, const tTarea &t2) {
    return t1.ini < t2.ini || (t1.ini == t2.ini && t1.fin < t2.fin);
}

bool resuelveCaso() {
    int ini, fin, t;
    // leer los datos de la entrada

    std::cin >> ini >> fin >> t;
    if (ini == 0 && fin == 0 && t ==0)
        return false;

    std::vector<tTarea>v(t);
    for (int i = 0; i < t; ++i) {
        std::cin >> v[i].ini >> v[i].fin;
    }
    sort(v.begin(), v.end());

    int trabajos = 0;
    int izq = ini, der = ini;
    for (int i = 0; i < t && der < fin; ++i) {
        if (v[i].ini <= izq && v[i].fin > der) {
            der = v[i].fin;
        }
        else {
            if (der == v[i].ini) {
                trabajos++;
                izq = v[i].ini;
                der = v[i].fin;
            }
        }
    }
    if (der == fin) trabajos++;
    else trabajos = -1;
    // resolver el caso posiblemente llamando a otras funciones

    if (trabajos != -1)
        std::cout << trabajos << "\n";
    else
        std::cout << "Imposible\n";
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
