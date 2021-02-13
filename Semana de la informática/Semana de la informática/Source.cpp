
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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
struct tActividad {
    int ini;
    int fin;
};

bool operator < (const tActividad &a1, const tActividad &a2) {
    return (a1.ini < a2.ini) || (a1.ini == a2.ini && a1.fin < a2.fin);
}

bool resuelveCaso() {
    int reuniones, ini, fin;
    // leer los datos de la entrada

    std::cin >> reuniones;
    if (reuniones == 0)
        return false;

    std::vector<tActividad> v;
    for (int i = 0; i < reuniones; ++i) {
        std::cin >> ini >> fin;
        v.push_back({ini, fin});
    }

    sort(v.begin(), v.end());
    priority_queue<int> compas;
    int cont = 0;
    compas.push(v[0].fin);
    for (int i = 1; i < reuniones; ++i) {
        if (!compas.empty() && compas.top() <= v[i].ini) {
            compas.pop();
        }
        else {
            cont++;
        }
        compas.push(v[0].fin);
        
    }
    // resolver el caso posiblemente llamando a otras funciones
    
    // escribir la solución
    std::cout << cont << "\n";

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
