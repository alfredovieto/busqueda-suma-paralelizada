#pragma once
#include "Calculadora.h"
#include "Datos.h"

class CalculadoraParalela : public Calculadora {
public:
    std::string nombre() const override;
    Resultado resolver(const int arr[], int n) override;
    void imprimirDetalle() const override;

private:
    ResultadoBloque bloques[NUM_BLOQUES];

    void procesarBloques(const int arr[], int n);
    Resultado combinarResultados() const;
};
