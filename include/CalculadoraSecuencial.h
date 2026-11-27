#pragma once
#include "Calculadora.h"

class CalculadoraSecuencial : public Calculadora {
public:
    std::string nombre() const override;
    Resultado resolver(const int arr[], int n) override;
};
