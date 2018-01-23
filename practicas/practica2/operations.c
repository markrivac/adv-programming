#include <assert.h>
#include "operations.h"
#define MAX_INT 2147483647
#define MIN_INT -2147483647

/**
 * Use long addition to catch overflow
 */

int add(int a, int b){

	// Do the addition and check if there is an overflow
	long c = (long) a + b;

	// Si la condición no se cumple, termina el programa.
	// MAX_INT y MIN_INT son los valores máximos y mínimos que puede guardar un long
	assert(c <= MAX_INT && c > MIN_INT);
	
	return (int)c;
	
}

int substract(int w, int x){

	long c = (long) w - x;

	assert(c <= MAX_INT && c > MIN_INT);
	
	return (int)c;

}