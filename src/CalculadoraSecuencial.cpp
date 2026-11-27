#include "CalculadoraSecuencial.h"

std::string CalculadoraSecuencial::nombre() const {
    return "PARTE 1. SOLUCION SECUENCIAL (1 recorrido de 0 a 99)";
}

// Un solo flujo recorre todo el arreglo y actualiza los tres valores.
Resultado CalculadoraSecuencial::resolver(const int arr[], int n) {
    Resultado r{0, arr[0], arr[0]};
    for (int i = 0; i < n; i++) {
        r.suma += arr[i];
        if (arr[i] > r.maximo) r.maximo = arr[i];
        if (arr[i] < r.minimo) r.minimo = arr[i];
    }
    return r;
}
