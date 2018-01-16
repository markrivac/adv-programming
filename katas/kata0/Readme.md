Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Break down:

¿Está ordenado? No.
¿Qué pasa si no hay resultado? Siempre debe haber dos números que den con el resultado.
¿Sólo números positivos? Sí.
¿Tamaño mínimo del arreglo? 2.
Caso más simple: El tamaño del arreglo es 2, regresa los únicos dos elementos.

Caso esperado: recorrer el arreglo, por cada elemento buscar su complemento para lograr el target en el resto del arreglo (lo que no se ha recorrido).

