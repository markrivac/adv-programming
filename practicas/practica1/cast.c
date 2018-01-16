#include <stdio.h>

int main(){
	int a = 4;
	int j;

	// Apuntador guarda la dirección de una variable en memoria
	// Con una dirección se puede modificar la dirección o el contenido de esa dirección
	int *p;
	float f = 7.5;
	int max = 2147483647;
	long d;
	int b = a + (int)f;
	float c = a*f;
	d = (long)max * max;
	p = &a;

	//Se modifica el contenido de la variable que apunta, pero la dirección no cambia
	*p = 7;
	p++;
	*p = 8;

	//Array en C
	//arreglo por sí solo es un apuntador
	//arreglo;
	int arreglo[5] = {0,2};
	p = arreglo;

	for (int i = 0; i < sizeof(arreglo)/sizeof(arreglo[0]); i++)
	{
		*p = 67;
		p++;

		//arreglo[k] = 67
		//p[k] = 67
	}

	printf("p= %p, a= %d, j = %d, b= %i, d= %li\n", p, a, j, b, d);
	printf("f = %f, c = %f, arreglo[1] = %d\n", f, c, arreglo[1]);

	return 0;
}