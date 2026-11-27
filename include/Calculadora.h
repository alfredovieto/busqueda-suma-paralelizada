#pragma once
#include <string>
#include "Resultado.h"

// Clase base abstracta: define qué debe hacer cualquier método de solución.
class Calculadora {
public:
    virtual ~Calculadora() = default;

    virtual std::string nombre() const = 0;
    virtual Resultado resolver(const int arr[], int n) = 0;
    virtual void imprimirDetalle() const {}

    void imprimir(const Resultado& r) const;
    double medirTiempo(const int arr[], int n, int repeticiones);
};
