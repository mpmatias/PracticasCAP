# Práctica 2

## OpenMP
* OpenMP explota el **paralelismo mediante hilos/threads**
* Un hilo es entidad más pequeña de procesamiento
    * Más liviano que un proceso
* Habitualmente, un número de hilos se pueden mapear sobre una máquina multiprocesador/core

### Paralelismo explícito
* OpenMP es un paradigma de programación explícito (no automático)
* Expresado mediante **directivas**
* Utiliza modelo **fork-join**
    * El hilo *master* crea un conjunto de hilos que acaban al finalizar la región paralela
    * Los hilos pueden colaborar

![image](figures/omp_exec_model.png)

### Soporte compilador
* En [Toolkit oneAPI HPC](https://www.intel.com/content/www/us/en/developer/tools/oneapi/hpc-toolkit.html) están disponibles los compiladores de C/C++ con soporte para OpenMP
    * Compilador clásico: icc/icpc
    * Compilador oneAPI DPC++/C++: icx/icpx

* Las pragmas OpenMP indican al compilador las regiones paralelas, y se compilan con la opción de compilador **-qopenmp**

### Hello World
* El [primer ejemplo](HelloWorld/hello.c) versará sobre la compilación y control de hilos de ejecución

```c
#include <stdio.h>
#include <omp.h>

int main(){

	// This code is executed by 1 thread
	printf("OpenMP with %d max threads\n", omp_get_max_threads () );
	printf("OpenMP with %d procs available\n", omp_get_num_procs () );

	#pragma omp parallel
	{
	// This code is executed in parallel
	// by multiple threads
	printf("Hello World from thread %d of %d threads\n",
		omp_get_thread_num(), omp_get_num_threads() );
	}
}
```
* Pudiendo compilar con ambos compiladores y generando el fichero de reportes

```sh
user@lab:~ $ icc -o hello.icc hello.c -qopenmp -qopt-report
user@lab:~ $ more hello.optrpt 

...
Begin optimization report for: main()

    Report from: OpenMP optimizations [openmp]

OpenMP Construct at hello.c(12,2)
remark #16201: OpenMP DEFINED REGION WAS PARALLELIZED
```

* Para controlar el número de hilos de ejecución se puede hacer de varias formas:
    * Variable de entorno **OMP_NUM_THREADS**
    * En la pragma ```#pragma omp parallel num_threads(3)```

```sh
user@lab:~ $ export OMP_NUM_THREADS=3
user@lab:~ $ ./hello.icc
OpenMP with 3 max threads
OpenMP with 4 procs available
Hello World from thread 0 of 3 threads
Hello World from thread 1 of 3 threads
Hello World from thread 2 of 3 threads
```

### 

## Cálculo potencial eléctrico
* Cálculo de potencial eléctrico, [código disponible](ElectricPotential/)
    * [Enlace al libro extraido](https://colfaxresearch.com/second-edition-of-parallel-programming-and-optimization-with-intel-xeon-phi-coprocessors/)
    * [Extraido del github!](https://github.com/ColfaxResearch/HOW-Series-Labs/tree/master/4/4.02-vectorization-data-structures-coulomb)

* 4 versiones
    * ver0: versión sin optimizar
        * Conviene prestar atención a las opciones de compilación (añadir arquitectura) y ver ineficiencias (conversiones de datos)
    * ver1: optimizado a la arquitectatura *target*, pero con ineficiencias de acceso a memoria (stride!=1)
        * Propuesta cambiar AoS por SoA
    * ver2: optimización de memoria
    * ver3: optimizacion de memoria a accesos alineados

# Tareas a realizar por el alumno
* Aplicar explotación SIMD utilizando la vectorización automática por parte del compilador en la aplicación de N-Body cuyo [código está disponible en el repositorio](NBody/)
    1. Vectorización autovectorizada
    2. Eliminación de "dependencias" en bucles (desalineación de punteros o \#pragma)
    3. Eliminación de conversión de tipos de datos (float/double)
    4. Accesos a memoria (**¿stride?**): SoA vs AoS
    5. Memoria alineada
* Uso de vectorización guiada porque en [algunos códigos](BlackScholes/) aparecen dependencias de datos aparentes que **inhiben la auyto-vectorización** por parte del compilador
    1. En el directorio "BlackScholes", al compilar con la opción de autovectorizacion (O2) y consultando el report del fichero fuente *black-scholes.c*, se puede ver el mensaje *vector dependence prevents vectorization*
    2. Se recomiendo usar alguna de las *pragma* estudias para "forzar" al compilador a generar código vectorial
```sh
LOOP BEGIN at black-scholes.c(82,5)
   remark #15344: loop was not vectorized: vector dependence prevents vectorization. First dependence is shown below. Use level 5 report for details
   remark #15346: vector dependence: assumed ANTI dependence between s0[i] (84:13) and vput[i] (100:9)
LOOP END
```

* Programación con Intrínsecas haciendo uso de la [Guía de Intrínsecas](https://software.intel.com/sites/landingpage/IntrinsicsGuide/) 
    * El código a utilizar está en el [directorio Intrinsics](Intrinsics/)



