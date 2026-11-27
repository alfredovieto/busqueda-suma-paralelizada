#include "CalculadoraParalela.h"
#include "Parciales.h"
#include <iomanip>
#include <iostream>

using namespace std;

string CalculadoraParalela::nombre() const {
    return "PARTE 2. SIMULACION PARALELA (4 bloques de 25 elementos)";
}

Resultado CalculadoraParalela::resolver(const int arr[], int n) {
    procesarBloques(arr, n);
    return combinarResultados();
}

// Divide el arreglo en bloques 0-24, 25-49, 50-74, 75-99.
// Cada bloque es un "procesador simulado" independiente de los demás.
void CalculadoraParalela::procesarBloques(const int arr[], int n) {
    int tam = n / NUM_BLOQUES;
    for (int b = 0; b < NUM_BLOQUES; b++) {
        int inicio = b * tam;
        int fin    = inicio + tam - 1;
        bloques[b] = {inicio, fin, {sumaParcial(arr, inicio, fin),
                                    maximoParcial(arr, inicio, fin),
                                    minimoParcial(arr, inicio, fin)}};
    }
}

// Reducción: suma de sumas, mayor de máximos y menor de mínimos.
Resultado CalculadoraParalela::combinarResultados() const {
    Resultado r = bloques[0].parcial;
    for (int b = 1; b < NUM_BLOQUES; b++) {
        const Resultado& p = bloques[b].parcial;
        r.suma += p.suma;
        if (p.maximo > r.maximo) r.maximo = p.maximo;
        if (p.minimo < r.minimo) r.minimo = p.minimo;
    }
    return r;
}

void CalculadoraParalela::imprimirDetalle() const {
    cout << "Bloque   Rango      Suma    Maximo   Minimo\n";
    for (int b = 0; b < NUM_BLOQUES; b++) {
        const ResultadoBloque& bl = bloques[b];
        cout << "  " << b + 1 << "     "
             << setw(2) << bl.inicio << " - " << setw(2) << bl.fin
             << setw(9) << bl.parcial.suma
             << setw(9) << bl.parcial.maximo
             << setw(9) << bl.parcial.minimo << "\n";
    }
    cout << "\nResultado combinado:\n";
}
