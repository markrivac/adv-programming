# Infographic
## Description
You want to build a word cloud, an infographic where the size of a word corresponds to how often it appears in the body of text.

To do this, you'll need data. Write code that takes a long string and builds its word cloud data in a hash table, where the keys are words and the values are the number of times the words occurred.

Think about capitalized words. For example, look at these sentences:

> "After beating the eggs, Dana read the next step:"  
> "Add milk and eggs, then add flour and sugar."

What do we want to do with "After", "Dana", and "add"? In this example, your final hash table should include one "Add" or "add" with a value of 2.

## Solution
Para esta solución, yo pienso en obtener las palabras desde un archivo para no hacer el input. La solución que considero más óptima es utilizar una Hashtable, en donde se vayan guardando la palabra como key y la cantidad de veces que aparece como value. 

Se revisan todas las palabras en el archivo, siguiendo las siguientes reglas:

- Para cada palabra en el archivo, se hace una búsqueda en la **hashtable** para saber si ya se encuentra agregada.
- Cada vez que se encuentra una nueva palabra, se agrega a la **hashtable** utilizando la palabra misma como *key* y se inicializa su value en 1.
- Cada vez que se encuentra una palabra repetida, el value de esa palabra en la **hastable** se incrementa.

```
hashtable -> newHash()
    palabra -> ""
    while enuentrePalabra:
        palabra -> uppercase(palabraActual)
        if hashtable.contains(palabra):
            palabra.value -> palabra.value + 1;
        else:
            palabra.value -> 1;
```