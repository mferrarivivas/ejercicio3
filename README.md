Ejercicio 3: Multiplicación de matriz por un vector.

Analizar diferentes soluciones paralelas para resolver la multiplicación de una matriz por un vector. Analice soluciones paralelas considerando los distintos tipos de particionado de datos.

Ejemplo: [falta imagen de ejemplo]

a) Resuelva el problema planteado considerando que cada proceso realiza la multiplicación de una fila de la matriz por el vector completo. Considera en la solución el siguiente esquema de código:
1. El proceso0 generará la matriz y el vector.
2. Las filas de la matriz se repartirán entre los procesos participantes. 
3. El vector se replicará en los procesos.
4. Cada proceso realizará las operaciones que le corresponden.
5. El vector resultado es reunido por el proceso0.
6. El proceso0 mostrará el resultado.

Observación: El programa debe ser parametrizable, es decir que el mismo debe solicitar el tamaño de la matriz antes de generarla. Asuma el caso más simple donde cuenta con tantos procesos como filas tenga la matriz.

b) Modifique el código anterior pensando que existen más filas que procesos para tratarlas. Considere dos casos:

● El número de filas de la matriz es múltiplo de la cantidad de procesos.

● El número de filas de la matriz no es múltiplo de la cantidad de procesos.
