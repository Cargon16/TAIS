
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

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

const int INF = 1000000000;

struct tCofre {
    int oro;
    int coste;
};

void resolver(std::vector<tCofre> &v, int T, int C, int &oroMax, std::vector<bool> &cofres, int &contCofres) {
    Matriz<int> m(C + 1, T + 1, 0);

    for (int i = 1; i <= C; ++i) {
        for (int j = 1; j <= T; ++j) {
            if (j < v[i - 1].coste) {
                m[i][j] = m[i - 1][j];
            }
            else {
                m[i][j] = std::max(m[i - 1][j], m[i-1][j-v[i-1].coste] + v[i-1].oro);
            }
        }
    }

    oroMax = m[C][T];
    int j = T;
   for(int i =C; i > 0; --i){
        if (m[i][j] == m[i - 1][j]) {
            cofres[i-1] = false;
        }
        else {
            cofres[i-1] = true;
            j -= v[i - 1].coste;
            contCofres++;
        }
    }
    
}

bool resuelveCaso() {
    int T, C;
    // leer los datos de la entrada

    std::cin >> T;
    if (!std::cin)  // fin de la entrada
        return false;

    std::cin >> C;
    std::vector<tCofre> v(C);

    for (int i = 0; i < C; ++i) {
        int m;
        std::cin >> m >> v[i].oro;
        v[i].coste = 3 * m;
    }
    // resolver el caso posiblemente llamando a otras funciones
    std::vector<bool>cofres(C);
    int contCofres =0, oro =0;
    resolver(v, T, C, oro, cofres, contCofres);
    std::cout << oro << "\n" << contCofres << "\n";
    if (contCofres > 0)
    for (int i = 0; i < cofres.size(); ++i) {
        if (cofres[i])
            std::cout << v[i].coste / 3 << " " << v[i].oro << "\n";
    }
    // escribir la solución
    std::cout << "---\n";

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
