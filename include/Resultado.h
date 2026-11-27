#pragma once

struct Resultado {
    int suma;
    int maximo;
    int minimo;

    bool operator==(const Resultado& otro) const {
        return suma == otro.suma && maximo == otro.maximo && minimo == otro.minimo;
    }
};

struct ResultadoBloque {
    int inicio;
    int fin;
    Resultado parcial;
};
