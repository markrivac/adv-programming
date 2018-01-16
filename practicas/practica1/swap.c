#include <stdio.h>

	//FUNCIONES
		//Regresar valores en una función
		//Pasa los datos por valor 
		//Se necesita pasar las direcciones de las variables para poder modificarlas

//no funciona
int swap_no(int a, int b){
	int t;
	t = a;
	a = b;
	b = t;
	return 0;
}

int swap(int *a, int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
	return 0;
}

int main(){
	int j=27, k=34;

	swap_no(j,k);
	printf("j = %d, k = %d\n", j, k );
	swap(&j, &k);
	printf("j = %d, k = %d\n", j, k );
	return 0;
}