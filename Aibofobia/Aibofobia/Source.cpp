
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "Matriz.h" // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
string reconstruir(string const& patitos, Matriz<int> const& patin,
    int i, int &j, int cont) {
    if (i > j || cont == 0) {
        if (i - 1 == -1)j = -1;
        else if(j ==0)j--;
        return {};
    }
    if (i == j) return { patitos[i] };
    if (patitos[i] == patitos[j])
        return reconstruir(patitos, patin, i + 1, --j, cont);
    else if (patin[i][j] == patin[i][j - 1] + 1) {
        int pos = j;
        return patitos[pos] + reconstruir(patitos, patin, i, --j, cont-1);
    }
        
    else
        return reconstruir(patitos, patin, i + 1, j, cont-1) + patitos[i];
}

int resolver(Matriz<int> &m, std::string &palabra) {
    for (int d = 1; d < palabra.size(); ++d) {
        for (int j = d; j < palabra.size(); ++j) {
            int i = j - d;

            if (palabra[i] == palabra[j])
                m[i][j] = m[i + 1][j - 1];
            else
                m[i][j] = std::min(m[i+1][j], m[i][j-1]) + 1;
        }
    }

    return m[0][palabra.size() - 1];
}

bool resuelveCaso() {
    std::string palabra;
    // leer los datos de la entrada

    std::cin >> palabra;
    if (!std::cin)  // fin de la entrada
        return false;

    Matriz<int> m(palabra.size(), palabra.size(), 0);
    // resolver el caso posiblemente llamando a otras funciones
    int letras = resolver(m, palabra), j = palabra.size() - 1;
    string sol, aux= "";
    sol = reconstruir(palabra, m, 0, j, letras);
    if (j == -1) aux = sol + palabra;
    else
    for (int i = 0; i < palabra.size(); ++i) {
        if (i == j) aux += palabra[i] + sol;
        else aux += palabra[i];
    }
    // escribir la solución
    std::cout << letras << " " << aux<< "\n";

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
