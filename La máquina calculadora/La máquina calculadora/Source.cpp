
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

const int MAX = 10000;

class ejercicio {
private:
    int conectado(int v, int i) {
        if (i == 0) return (v + 1) % MAX;
        if (i == 1) return (v * 2) % MAX;
        else return v / 3;
    }

    int bfs(int inicio, int dest) {
        if (inicio == dest) return 0;
        std::vector<int> distancia(MAX, -1);
        distancia[inicio] = 0;
        std::queue<int> q;
        q.push(inicio);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int i = 0; i < 3; ++i) {
                int num = conectado(v, i);
                if (distancia[num] == -1) {
                    distancia[num] = distancia[v] + 1;
                    if (num == dest) return distancia[num];
                    else q.push(num);
                }
            }
        }

    }

public:
    ejercicio(int ini, int fin) {
        int sol = bfs(ini, fin);
        std::cout << sol << "\n";
    }


};

bool resuelveCaso() {
    int ini, fin;
    // leer los datos de la entrada

    std::cin >> ini >> fin;
    if (!std::cin)  // fin de la entrada
        return false;

    ejercicio p(ini, fin);
    // resolver el caso posiblemente llamando a otras funciones

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
