#include "Calculadora.h"
#include <chrono>
#include <iostream>

using namespace std;

void Calculadora::imprimir(const Resultado& r) const {
    cout << "   Suma total : " << r.suma   << "\n";
    cout << "   Maximo     : " << r.maximo << "\n";
    cout << "   Minimo     : " << r.minimo << "\n\n";
}

// Promedio en ns de una ejecución. resolver() se llama de forma polimórfica.
double Calculadora::medirTiempo(const int arr[], int n, int repeticiones) {
    volatile int sumidero = 0;  // evita que el compilador elimine el cálculo
    auto t0 = chrono::high_resolution_clock::now();
    for (int k = 0; k < repeticiones; k++)
        sumidero = sumidero + resolver(arr, n).suma;
    auto t1 = chrono::high_resolution_clock::now();
    return chrono::duration<double, nano>(t1 - t0).count() / repeticiones;
}
