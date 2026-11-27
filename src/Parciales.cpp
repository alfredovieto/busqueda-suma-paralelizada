#include "Parciales.h"

int sumaParcial(const int arr[], int inicio, int fin) {
    int suma = 0;
    for (int i = inicio; i <= fin; i++) suma += arr[i];
    return suma;
}

int maximoParcial(const int arr[], int inicio, int fin) {
    int maximo = arr[inicio];
    for (int i = inicio + 1; i <= fin; i++)
        if (arr[i] > maximo) maximo = arr[i];
    return maximo;
}

int minimoParcial(const int arr[], int inicio, int fin) {
    int minimo = arr[inicio];
    for (int i = inicio + 1; i <= fin; i++)
        if (arr[i] < minimo) minimo = arr[i];
    return minimo;
}
