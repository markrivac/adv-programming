Instrucciones:

Given two lists Aand B, and B is an anagram of A. B is an anagram of A means B is made by randomizing the order of the elements in A.

We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.

These lists A and B may contain duplicates. If there are multiple answers, output any of them.

Análisis:

Se dan dos listas: A y B, donde B es un anagrama de A.
Se quiere encontrar un mapeo de índice P de A hacia B.
Un mapeo[i]=j significa que el elemento i en A aparece en B en la posición j.

Datos importantes:
. B es un anagrama de A, esto quiere decir que los elementos de B son los mismos que en A, pero ordenados aleatoriamente.
. Las listas A y B pueden contener elementos duplicados, lo que quiere decir que va a haber múltiples respuestas. Sólo se necesita obtener una de estas.
. A y B son del mismo tamaño, en un rango de [0,100].
. A[i] y B[j] son integers que se encuentran en un rango [1,10^5].

Ejemplo:

A = [12, 28, 46, 32, 50] y B = [50, 12, 32, 46, 28].

La respuesta a este ejemplo sería P = [1, 4, 3, 2, 0].

¿Cómo lo resolvería?

Básicamente, lo que veo aquí es un problema que trata de buscar los elementos que se encuentran en A en el arreglo B y guardar la posición de estos últimos en un arreglo P. 

Entonces, lo primero que se debe de pensar es en cuál algoritmo de búsqueda es el que mejor se acomoda a las necesidades del problema. Para esto identifico dos cosas importantes:
1. Se puede dar el caso que los elementos de A estén ordenados. Sin embargo, hablando de B, esto es muy complicado ya que forsozamente estarán ordenados de manera aleatoria.
2. El tamaño de los arreglos es "pequeño", el máximo posible sería un arreglo con 100 elementos.

Teniendo en cuenta esto, un Algoritmo de búsqueda binaria no funcionaría debido a que los elementos del arreglo no van a estar ordenados en la gran mayoría de los casos. Entonces, se podría pensar en ordenarlos guardando sus posiciones originales como su llave o con algo por el mismo estilo, pero debido a la complejidad de los arreglos, una búsqueda lineal funciona bien y es fácil de programar, mucho más entendible ante otros programadores.

El siguiente paso es crear un arreglo que sea de igual tamaño que A y B, este sería en donde se guardarían los índices de los elementos, llamémoslo P.

A continuación, solo se hace uso del algoritmo de búsqueda para encontrar los elementos de A en B y guardar su posición en P.

Pseudocódigo:

Array A;
Array B;
Array P;

for each i in A:
	for each j in B:
		if A[i] == B[j]:
			P[i] = j;
	end;
end;














