## Kata4: Valid Number

### Problema
Es necesario desarrollar una función que indique si una cadena de caracteres contiene un valor numérico o no. Algunos ejemplos son:
* 1
* 0.1, .1
* +1, -1
* 1e2, 1e+2, 1e-1
* 1,000, 1,000.00

### Solución
La función consiste en recorrer todo el arreglo de caracteres:
* Verifica si el primer elemento es un + o un -.
* Verifica que la cadena formada por el análisis de los caracteres sea:
    * a. Un número natural.
    * b. Un número decimal.
    * c. Un número exponencial.

#### La función regresa 1 en caso de que sea válido, si no se cumple con alguna validación, regresa 0.