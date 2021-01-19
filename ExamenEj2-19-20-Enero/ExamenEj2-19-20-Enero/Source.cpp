
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include "Digrafo.h"
#include <queue>

class recorridoProfundidad {
private:
    std::vector<bool> visitados;
    std::vector<bool> apilados;
    std::deque<int>q;
    bool ciclo;
    void dfs(const Digrafo& g, int v) {
        visitados[v] = true;
        apilados[v] = true;
        for (auto aux : g.ady(v)) {
            if (ciclo) return;
            if (apilados[aux]) ciclo = true;
            else if (!visitados[aux]) {
                dfs(g, aux);
            }
        }
        apilados[v] = false;
        q.push_front(v);
    }
public:
    recorridoProfundidad(const Digrafo& g, int v) :visitados(g.V(), false), apilados(g.V(), false), ciclo(false) {
        for (int i = 0; i < g.V(); ++i) {
            if (!visitados[i])
                dfs(g, i);
        }
    }

    std::deque<int> getOrden() {
        return q;
    }
    bool getCiclo() {
        return ciclo;
    }
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada
    Digrafo g(std::cin, 1);
    if (!std::cin)  // fin de la entrada
        return false;

    recorridoProfundidad p(g, 0);
    std::deque<int> q = p.getOrden();
    if(p.getCiclo())
        std::cout << "Imposible\n";
    else{
        for (auto it = q.cbegin(); it != q.cend(); ++it) {
            std::cout << *it + 1 << " ";
        }
        std::cout << "\n";
    } 

    // escribir sol

    return true;
}

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
