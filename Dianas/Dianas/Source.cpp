
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
struct tCuerda {
    int longitud;
    int coste;
};

const int INF = 1000000000;

bool sePuede(std::vector<tCuerda>& v, int P) {
    Matriz<bool> m(v.size() + 1, P + 1, false);

    m[0][0] = true;
    for (int i = 1; i <= v.size(); ++i) {
        m[i][0] = true;
        for (int j = 1; j <= P; ++j) {
            if (j < v[i - 1].longitud)
                m[i][j] = m[i - 1][j];
            else
                m[i][j] = m[i - 1][j] || m[i - 1][j - v[i - 1].longitud];
        }
    }

    return m[v.size()][P];
}

int formas(std::vector<tCuerda> &v, int P) {
    Matriz<int> m(v.size()+1, P+1, 0);

    m[0][0] = 1;
    for (int i = 1; i <= v.size(); ++i) {
        m[i][0] = 1;
        for (int j = 1; j <= P; ++j) {
            if (j < v[i - 1].longitud)
                m[i][j] = m[i - 1][j];
            else
                m[i][j] = m[i - 1][j] + m[i - 1][j - v[i - 1].longitud];
        }
    }

    return m[v.size()][P];
}

int coste(std::vector<tCuerda>& v, int P) {
    Matriz<int> m(v.size() + 1, P + 1, INF);

    m[0][0] = 0;
    for (int i = 1; i <= v.size(); ++i) {
        m[i][0] = 0;
        for (int j = 1; j <= P; ++j) {
            if (j < v[i - 1].longitud)
                m[i][j] = m[i - 1][j];
            else
                m[i][j] = std::min(m[i-1][j], m[i-1][j - v[i-1].longitud] + v[i-1].coste);
        }
    }

    return m[v.size()][P];
}

int minCuerdas(std::vector<tCuerda>& v, int P) {
    Matriz<int> m(v.size() + 1, P + 1, INF);

    m[0][0] = 0;
    for (int i = 1; i <= v.size(); ++i) {
        m[i][0] = 0;
        for (int j = 1; j <= P; ++j) {
            if (j < v[i - 1].longitud)
                m[i][j] = m[i - 1][j];
            else
                m[i][j] = std::min(m[i - 1][j], m[i - 1][j - v[i - 1].longitud] + 1);
        }
    }

    return m[v.size()][P];
}

bool resuelveCaso() {
    int C, P;
    // leer los datos de la entrada

    std::cin >> C >> P;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<tCuerda> v(C);
    for (int i = 0; i < C; ++i) {
        std::cin >> v[i].longitud >> v[i].coste;
    }
    // resolver el caso posiblemente llamando a otras funciones
    if (sePuede(v, P)) {
        std::cout << "SI " << formas(v, P) << " " << minCuerdas(v, P) << " " << coste(v, P) << "\n";
    }
    else
        std::cout << "NO\n";
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
