
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
