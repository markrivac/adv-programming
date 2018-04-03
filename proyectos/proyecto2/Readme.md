# The Last Word 

### Problem

On the game show The Last Word, the host begins a round by showing the contestant a string S of uppercase English letters. The contestant has a whiteboard which is initially blank. The host will then present the contestant with the letters of S, one by one, in the order in which they appear in S. When the host presents the first letter, the contestant writes it on the whiteboard; this counts as the first word in the game (even though it is only one letter long). After that, each time the host presents a letter, the contestant must write it at the beginning or the end of the word on the whiteboard before the host moves on to the next letter (or to the end of the game, if there are no more letters).

For example, for S = CAB, after writing the word C on the whiteboard, the contestant could make one of the following four sets of choices:

- put the A before C to form AC, then put the B before AC to form BAC
- put the A before C to form AC, then put the B after AC to form ACB
- put the A after C to form CA, then put the B before CA to form BCA
- put the A after C to form CA, then put the B after CA to form CAB

The word is called the last word when the contestant finishes writing all of the letters from S, under the given rules. The contestant wins the game if their last word is the last of an alphabetically sorted list of all of the possible last words that could have been produced. For the example above, the winning last word is CAB (which happens to be the same as the original word). For a game with S = JAM, the winning last word is MJA.

You are the next contestant on this show, and the host has just showed you the string S. What's the winning last word that you should produce?

#### Input 
The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each consists of one line with a string **S**.

#### Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the winning last word, as described in the statement.


## Breakdown

    Este problema consiste en realizar una serie de combinaciones con una cadena dada siguiendo ciertas reglas. La que me parece la principal sería que las combinaciones estén ordenadas alfabéticamente.

### Solución

Para este problema la solución no me parece tan complicada. Consiste en recibir n cadenas, aunque me voy a referir sólo a una para la explicación. La cadena que se recibe consta de ciertas letras y a partir de ellas se forman más cadenas abarcando las posibles combinaciones.

Primero es obtener la cadena, ya sea de un input normal en consola o desde un archivo de texto. Después se obtiene el caracter inicial de la cadena. A partir de este se empiezan a generar las cadenas resultantes de las combinaciones.

La cadena inicial se va recorriendo de izquierda a derecha y cada letra que se encuentra se va poniendo detrás o delante de la última procesada. Al final, la *palabra* ganadora es la que queda al último ordenando las distintas palabras formadas de manera alfabéticamente.

Lo que se me ocurre para lograr esto es que cada letra que se va encontrando, se coloque delante (derecha) o atrás (izquierda) dependiendo del *peso* de la letra. De manera que las letras pesadas se ubiquen del lado trasero (Izquierda) y, así, al momento de ordenar las palabras, estas se irían hasta al final de la lista por su orden alfabético.

#### Pseudocódigo

    theLastWord(string string){
        lastword -> empty
        char[] caracteres -> string.toCharArray();
        firstWord -> caracteres[0];
        lastword -> firstWord;
        for (car: caracteres):
            if (car < lastword at left side):
                lastword at right side -> car;
            else:
                lastword at left side -> car;
        return lastword;
    }

