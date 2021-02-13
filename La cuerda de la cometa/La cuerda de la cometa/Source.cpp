
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

 El problema se calcula en 4 funciones, una para cada uno de los datos que se nos piden
 El coste de todas las funciones es O(C*L), siendo C el número de filas(las cuerdas) y L las columnas(la longitud)

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


/*
esPosible(i, j) = {
    esPosible(i-1, j) si li > j
	esPosible(i-1, j-li) si li <= j � esPosible(i-1, j) si li <= j
}
li es la longitud de la cuerda i
*/
bool esPosible(std::vector<tCuerda>& v, int C, int L) {
    Matriz<bool> esPosible(C + 1, L + 1, false);

    esPosible[0][0] = true;

    for (int i = 1; i <= C; i++) {
        esPosible[i][0] = true;
        for (int j = 1; j <= L; j++) {

            if (v[i-1].longitud > j) {
                esPosible[i][j] = esPosible[i - 1][j];
            }
            else {
                esPosible[i][j] = (esPosible[i - 1][j - v[i-1].longitud] || esPosible[i - 1][j]);
            }
        }
    }

    return esPosible[C][L];
}

/*
minCoste = {
    minCoste(i-1, j) si li > j
    min(minCoste(i-1, j-li) + ci, minCoste(i-1, j)) si li <= j
}
ci es el coste de la cuerda i
*/
int64_t minCoste(std::vector<tCuerda> &v, int C, int L) {
    Matriz<int64_t>m(C+1, L+1, INF);
    m[0][0] =0;
    for (int i = 1; i <= C; ++i) {
        m[i][0] = 0;
        for (int j = 1; j <= L; ++j) {
            if (v[i - 1].longitud > j)
                m[i][j] = m[i - 1][j];
            else {
                m[i][j] = std::min(m[i-1][j], v[i-1].coste + m[i-1][j-v[i-1].longitud]);
            }
        }
    }

    return m[C][L];
}


/*
numMinCuerdas = {
    numMinCuerdas(i-1, j) si li > j
    min(numMinCuerdas(i-1, j-li) +  1, numMinCuerdas(i-1, j)) si li <= j

*/

int64_t numMinCuerdas(std::vector<tCuerda>& v, int C, int L) {
    Matriz<int64_t>m(C + 1, L + 1, INF);
    m[0][0] =0;
    for (int i = 1; i <= C; ++i) {
        m[i][0] = 0;
        for (int j = 1; j <= L; ++j) {
            if (v[i - 1].longitud > j)
                m[i][j] = m[i - 1][j];
            else {
                m[i][j] = std::min(m[i - 1][j], 1 + m[i - 1][j - v[i - 1].longitud]);
            }
        }
    }

    return m[C][L];
}

/*
posibilidades = {
    posibilidades(i-1, j) si li > j
    posibilidades(i-1, j-li) + posibilidades(i-1, j) si li <= j
}
*/

int64_t posibilidades(std::vector<tCuerda>& v, int C, int L) {
    Matriz<int64_t>m(C + 1, L + 1, 0);
    m[0][0] = 1;
    for (int i = 1; i <= C; ++i) {
        m[i][0] = 1;
        for (int j = 1; j <= L; ++j) {
            if (v[i - 1].longitud > j)
                m[i][j] = m[i - 1][j];
            else {
                m[i][j] = (m[i - 1][j] + m[i - 1][j - v[i - 1].longitud]);
            }
        }
    }

    return m[C][L];
}

bool resuelveCaso() {
    int C, L;
    // leer los datos de la entrada

    std::cin >> C >> L;
    if (!std::cin)  // fin de la entrada
        return false;

    std::vector<tCuerda> v(C);
    for (int i = 0; i < C; ++i) {
        std::cin >> v[i].longitud >> v[i].coste;
    }

    bool posible = esPosible(v, C, L);

    // resolver el caso posiblemente llamando a otras funciones
    if (!posible)
        std::cout << "NO\n";
    else {
        int64_t coste = minCoste(v, C, L);
        int64_t cuerdas = numMinCuerdas(v, C, L);
        int64_t pos = posibilidades(v, C, L);
        std::cout << "SI " << pos << " " << cuerdas << " " << coste << "\n";
    }
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
