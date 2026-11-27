# Búsqueda y Suma Paralelizada

Proyecto ordinario de **Arquitectura de Computadoras**.

Sobre un arreglo fijo de 100 enteros se calculan la **suma total**, el **máximo** y el **mínimo** de dos formas:

1. **Secuencial:** un solo recorrido de 0 a 99.
2. **Paralela simulada:** el arreglo se divide en 4 bloques de 25 elementos. Cada bloque actúa como un "procesador" independiente y al final se combinan los resultados parciales (reducción).

El programa comprueba que ambos métodos den el mismo resultado y compara los pasos teóricos y el tiempo medido de cada uno.

## Estructura

```
.
├── include/                   Encabezados (.h)
│   ├── Calculadora.h          Clase base abstracta
│   ├── CalculadoraSecuencial.h
│   ├── CalculadoraParalela.h
│   ├── Parciales.h            Suma/máximo/mínimo sobre un rango
│   ├── Resultado.h            Structs Resultado y ResultadoBloque
│   └── Datos.h                Arreglo de entrada y constantes
├── src/                       Implementación (.cpp)
│   ├── main.cpp
│   ├── Calculadora.cpp
│   ├── CalculadoraSecuencial.cpp
│   ├── CalculadoraParalela.cpp
│   └── Parciales.cpp
├── docs/
│   └── salida_ejecucion.txt   Ejemplo de salida del programa
├── CMakeLists.txt
└── README.md
```

## Compilar y ejecutar

Todos los comandos se ejecutan desde la raíz del proyecto. Se requiere C++17.

**g++ (MinGW / Linux):**

```bash
mkdir -p build
g++ -std=c++17 -Iinclude src/*.cpp -o build/proyecto
./build/proyecto
```

**MSVC (Developer Command Prompt de Visual Studio):**

```bat
mkdir build
cl /std:c++17 /EHsc /Iinclude src\*.cpp /Fobuild\ /Febuild\proyecto.exe
build\proyecto.exe
```

**CMake:**

```bash
cmake -S . -B build
cmake --build build
```

## Resultado esperado

| Métrica | Valor |
|---|---|
| Suma total | 53917 |
| Máximo | 976 |
| Mínimo | 3 |
| Speedup teórico (4 núcleos) | 100 / 28 ≈ 3.57x |

La versión paralela es una simulación: corre en un solo núcleo, un bloque tras otro, por lo que en tiempo real es más lenta que la secuencial. La ventaja aparece cuando cada bloque se ejecuta en un núcleo distinto. La salida completa está en [docs/salida_ejecucion.txt](docs/salida_ejecucion.txt).
