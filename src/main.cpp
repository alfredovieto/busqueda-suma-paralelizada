/*
 * Arquitectura de Computadoras - Búsqueda y Suma Paralelizada
 * Compilar (desde la raíz del proyecto):
 *   g++ -std=c++17 -Iinclude src/*.cpp -o build/proyecto
 */
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>
#include "Datos.h"
#include "CalculadoraSecuencial.h"
#include "CalculadoraParalela.h"

using namespace std;

const int REPETICIONES = 1000000;

void imprimirLinea() {
    cout << "-------------------------------------------------------------\n";
}

void imprimirArreglo() {
    cout << "Arreglo de entrada (" << TAMANO << " enteros):\n";
    for (int i = 0; i < TAMANO; i++) {
        cout << setw(4) << DATOS[i];
        if ((i + 1) % 10 == 0) cout << "\n";
    }
    cout << "\n";
}

void imprimirVerificacion(const Resultado& sec, const Resultado& par) {
    imprimirLinea();
    cout << "VERIFICACION\n";
    imprimirLinea();
    cout << "   Suma   : " << (sec.suma   == par.suma   ? "OK" : "ERROR") << "\n";
    cout << "   Maximo : " << (sec.maximo == par.maximo ? "OK" : "ERROR") << "\n";
    cout << "   Minimo : " << (sec.minimo == par.minimo ? "OK" : "ERROR") << "\n";
    cout << (sec == par ? "   >> Ambos metodos COINCIDEN.\n\n"
                        : "   >> Los metodos NO coinciden.\n\n");
}

void imprimirComparacion(double tSec, double tPar) {
    int pasosParalelo = TAM_BLOQUE + (NUM_BLOQUES - 1);   // 25 + 3 con 4 núcleos

    imprimirLinea();
    cout << "COMPARACION SECUENCIAL vs PARALELO\n";
    imprimirLinea();
    cout << fixed << setprecision(2);
    cout << "   Pasos secuencial                  : " << TAMANO << "\n";
    cout << "   Pasos paralelo (4 nucleos reales) : " << TAM_BLOQUE << " + "
         << NUM_BLOQUES - 1 << " de combinacion = " << pasosParalelo << "\n";
    cout << "   Speedup teorico                   : "
         << (double)TAMANO / pasosParalelo << "x\n\n";
    cout << "   Tiempo medido (promedio de " << REPETICIONES << " ejecuciones):\n";
    cout << "      Secuencial          : " << tSec << " ns\n";
    cout << "      Paralelo simulado   : " << tPar << " ns\n";
    cout << "      Relacion par/sec    : " << tPar / tSec << "\n\n";
    cout << "   Nota: la version paralela es una SIMULACION; corre en un solo\n";
    cout << "   nucleo, un bloque tras otro, y recorre cada bloque 3 veces.\n";
    cout << "   La ventaja aparece cuando cada bloque usa un nucleo distinto.\n";
}

int main() {
    cout << "=============================================================\n";
    cout << "   BUSQUEDA Y SUMA PARALELIZADA - Arquitectura de Computadoras\n";
    cout << "=============================================================\n\n";
    imprimirArreglo();

    vector<unique_ptr<Calculadora>> metodos;
    metodos.push_back(make_unique<CalculadoraSecuencial>());
    metodos.push_back(make_unique<CalculadoraParalela>());

    vector<Resultado> resultados;
    vector<double> tiempos;

    // Polimorfismo: la misma llamada ejecuta el algoritmo de cada clase derivada.
    for (auto& metodo : metodos) {
        imprimirLinea();
        cout << metodo->nombre() << "\n";
        imprimirLinea();

        Resultado r = metodo->resolver(DATOS, TAMANO);
        metodo->imprimirDetalle();
        metodo->imprimir(r);

        resultados.push_back(r);
        tiempos.push_back(metodo->medirTiempo(DATOS, TAMANO, REPETICIONES));
    }

    imprimirVerificacion(resultados[0], resultados[1]);
    imprimirComparacion(tiempos[0], tiempos[1]);
    return 0;
}
