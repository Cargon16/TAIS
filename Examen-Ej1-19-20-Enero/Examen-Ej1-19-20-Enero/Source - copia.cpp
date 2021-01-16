
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "IndexPQ.h"
#include <vector>

struct tBateria {
    int id;
    int capIni;
    int capActual;
};

bool operator < (const tBateria &b1, const tBateria &b2) {
    if (b1.capActual < b2.capActual) return true;
    else return false;
}

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
void resolver(IndexPQ<tBateria> &c, std::vector<tBateria> &v, std::vector<tBateria> &v1 , int z, int t) {
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < v1.size(); ++j) {
            tBateria b = v1[j];
            b.capActual--;
            v1[j].capActual--;
            if (b.capActual == 0) b.capActual = b.capIni - z;
            if (b.capActual <= 0) {
                if (!v.empty()) {
                    tBateria b1 = v.back();
                    b1.id = v1.size();
                    c.update(c.top().elem, b1);
                    v1.push_back(b1);
                    v.pop_back();
                    
                }
            }
            else
                c.update(j, b);
        }
    }
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int b;
    // leer los datos de la entrada
    std::cin >> b;
    if (!std::cin)  // fin de la entrada
        return false;
    tBateria bat;
    IndexPQ<tBateria> c(b);
    std::vector<tBateria> v1;
    int cap;
    for (int i = 0; i < b; ++i) {
        std::cin >> cap;
        bat.id = i;
        bat.capActual = cap;
        bat.capIni = cap;
        c.push(i, bat);
        v1.push_back(bat);
    }

    int aux;
    std::cin >> aux;
    std::vector<tBateria> v(aux);
    for (int i = aux-1; i >= 0; --i) {
        std::cin >> cap;
        v[i] = {0, cap, cap};
    }

    int z, t;
    std::cin >> z >> t;
    resolver(c, v, v1, z, t);

    if (c.empty()) std::cout << "ABANDONEN INMEDIATAMENTE LA BASE\n";
    else {
        if (c.size() == b) std::cout << "CORRECTO\n";
        else std::cout << "FALLO EN EL SISTEMA\n";
        while (!c.empty()) {
            std::cout << c.top().elem + 1 << " " << c.top().prioridad.capActual + t << "\n";
            c.pop();
        }
    }
    std::cout << "---\n";

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
