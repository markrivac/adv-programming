#include <stdio.h>
#include "operations.h"


int testAddition();
int testSubstraction();

void printTestMessage(int condition, char *messagePassed, char *messageFailed){
	if (condition)
	{
		printf("%s\n", messagePassed);
	}
	else{
		printf("%s\n", messageFailed);
	}
}

int testAddition(){

	int a = 5;
	int b = 4;
	int result = add(a,b);
	int expected = a + b;

	return result == expected;

}

int testSubstraction(){

	int w = 10;
	int x = 5;
	int subResult = substract(w,x);
	int subExpected = w - x;

	return subExpected == subResult;

}

int main(){

	printTestMessage(testSubstraction(),
					 "Substraction test passed",
					 "Substraction test Failed");

	printTestMessage(testAddition(),
					 "Substraction test passed",
					 "Substraction test Failed");

	return 0;
}