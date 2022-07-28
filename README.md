# Repositorio para las prácticas de la asignatura de CAP

## Práctica 1 (Explotación paralelismo vectorial)
* Pequeños vectores = SIMD  (Single Instruction Multiple Data)

### Opciones de Compilación
* Opciones del compilador para llevar a cabo optimizaciones

### Autovectorización
* La opción **-O2** habilita al autovectorizador

```console
user@lab:~ $ more fooO2.optrpt 
Intel(R) Advisor can now assist with vectorization and show optimization
  report messages with your source code.
See "https://software.intel.com/en-us/intel-advisor-xe" for details.

Intel(R) C Intel(R) 64 Compiler for applications running on Intel(R) 64, Version 19.0.4.235 Build 20190416

Compiler options: -o fooO2 -O2 -qopt-report=3 -xhost -lm

    Report from: Interprocedural optimizations [ipo]

Intel(R) Advisor can now assist with vectorization and show optimization
  report messages with your source code.
See "https://software.intel.com/en-us/intel-advisor-xe" for details.

Intel(R) C Intel(R) 64 Compiler for applications running on Intel(R) 64, Version 19.0.4.235 Build 20190416

Compiler options: -o fooO2 -O2 -qopt-report=3 -xhost -lm

...

LOOP BEGIN at fooO0.c(23,2) inlined into fooO0.c(58,2)
   remark #15300: LOOP WAS VECTORIZED
   remark #15442: entire loop may be executed in remainder
   remark #15450: unmasked unaligned unit stride loads: 1 
   remark #15451: unmasked unaligned unit stride stores: 1 
   remark #15475: --- begin vector cost summary ---
   remark #15476: scalar cost: 111 
   remark #15477: vector cost: 20.750 
   remark #15478: estimated potential speedup: 4.780 
   remark #15482: vectorized math library calls: 1 
   remark #15487: type converts: 2 
   remark #15488: --- end vector cost summary ---
LOOP END
```

### Análisis del compilador para mejorar rendimiento con Autovectorización
* Detección de cuellos de botella
* Eliminación de operaciones de conversiones de datos
* Selección de flags de arquitectura
* Mejora de lay-out memoria




