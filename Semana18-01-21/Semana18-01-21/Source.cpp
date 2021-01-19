
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"
#include <vector>
#include <algorithm>

struct tCancion {
    double duracion;
    double puntuacion;
};

struct tNodo {
    std::vector<bool> caraA;//Sol
    std::vector<bool> caraB;//Sol
    int k;
    double pesoA;
    double pesoB; // peso acumulado
    double beneficio; // valor acumulado
    double beneficio_est; // prioridad
    bool operator>(tNodo const& otro) const {
        return otro.beneficio_est > beneficio_est;
    }
};

bool comparador(const tCancion& c1, const tCancion& c2) {
    return (c1.puntuacion / c1.duracion > c2.puntuacion / c2.duracion);
}

double calculo_voraz(std::vector<tCancion> const& objetos, double D, tNodo const& X) {
    double hueco = (D*2) - (X.pesoA + X.pesoB), estimacion = X.beneficio;
    int i = X.k + 1;
    while (i < objetos.size() && objetos[i].duracion <= hueco) {
        // podemos coger el objeto j entero
        hueco -= objetos[i].duracion;
        estimacion += objetos[i].puntuacion;
        ++i;
    }
    if (i < objetos.size())
        estimacion += (hueco / objetos[i].duracion) * objetos[i].puntuacion;
    return estimacion;
}

void cancion_rp(std::vector<tCancion> &v, double D, std::vector<bool> &solMejor, double &beneficioMejor) {
    int N = v.size();

    tNodo Y;
    Y.caraA = std::vector<bool>(N);
    Y.caraB = std::vector<bool>(N);
    Y.k = -1;
    Y.pesoA = Y.pesoB = Y.beneficio = 0;
    Y.beneficio_est = calculo_voraz(v, D, Y);
    
    PriorityQueue<tNodo, std::greater<tNodo>> cola;
    cola.push(Y);
    beneficioMejor = -1;

    while (!cola.empty() && cola.top().beneficio_est > beneficioMejor) {
        Y = cola.top(); cola.pop();
        tNodo X(Y);
        ++X.k;
        // probamos a meter el objeto en la mochila
        if (Y.pesoA + v[X.k].duracion <= D) {
            X.caraA[X.k] = true;
            X.pesoA = Y.pesoA + v[X.k].duracion;
            X.beneficio = Y.beneficio + v[X.k].puntuacion;
            X.beneficio_est = Y.beneficio_est;
            if (X.k == N - 1) {
                solMejor = X.caraA; beneficioMejor = X.beneficio;
            }
            else cola.push(X);
        }

        if (Y.pesoB + v[X.k].duracion <= D) {
            X.caraB[X.k] = true;
            X.pesoB = Y.pesoB + v[X.k].duracion;
            X.beneficio = Y.beneficio + v[X.k].puntuacion;
            X.beneficio_est = Y.beneficio_est;
            if (X.k == N - 1) {
                solMejor = X.caraA; beneficioMejor = X.beneficio;
            }
            else cola.push(X);
        }

        // probar a no meter el objeto
        X.caraB[X.k] = false;
        X.pesoB = Y.pesoB; X.beneficio = Y.beneficio;
        X.beneficio_est = calculo_voraz(v, D, X);
        if (X.beneficio_est > beneficioMejor) {
            if (X.k == N - 1) {
                solMejor = X.caraB; beneficioMejor = X.beneficio;
            }
            else
                cola.push(X);
        }
    }

}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int canciones, duracion;
    // leer los datos de la entrada
    std::cin >> canciones;
    if (canciones ==0)
        return false;

    std::cin >> duracion;
    std::vector<tCancion> v(canciones);
    for (int i = 0; i < canciones; ++i)
        std::cin >> v[i].duracion >> v[i].puntuacion;

    sort(v.begin(), v.end(), comparador);
    std::vector<bool> solMejor;
    double beneficioMejor;

    cancion_rp(v, duracion, solMejor, beneficioMejor);
    std::cout << beneficioMejor << "\n";
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
