
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>
int resolver(std::vector<int>& v, int& N) {
    int n = v.size();
    Matriz<int> m(n, n, 0);


	for (int d = 1; d <= N - 1; ++d)
	{
		for (int i = 0; i < N - d; ++i)
		{
			int j = i + d;
			if (j == i + 1) //no hay dos trozos iguales seguidos
			{
				m[i][j] = 0;
			}
			else if (i < j)
			{
				int valor = std::max(m[i + 2][j], m[i][j - 2]);
				valor = std::max(valor, m[i + 1][j - 1] + ((v[i] == v[j]) && (v[i] != 0)));
				m[i][j] = valor;
			}
		}
	}

	return m[0][N - 1];
}

bool resuelveCaso() {
    int T;
    // leer los datos de la entrada

    std::cin >> T;
    if (!std::cin)  // fin de la entrada
        return false;
    std::vector<int> v(T + 1, 0);
    // resolver el caso posiblemente llamando a otras funciones

    for (int i = 0; i < T; ++i)
        std::cin >> v[i];
    // escribir la soluci�n

    std::cout << resolver(v, T) << "\n";

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
