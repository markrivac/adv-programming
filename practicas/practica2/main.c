#include <stdio.h>
#include <string.h>
#include "operations.h"
#include "messages.h"

#define MAX_STRING_LENGTH 100
#define LANG "eng"

typedef struct {
	char *operationName;
	int(*operation) (int, int);
} Operation;

int main(){
	char operation[MAX_STRING_LENGTH];
	int operatorOne, operatorTwo;
	char **message;

	if (!strcmp(LANG, "eng"))
	{
		message = message_ENG;
	}
	
	if (!strcmp(LANG, "spa"))
	{
		message = message_SPA;
	}

	printf("%s\n", message[0]);
	scanf("%s",operation);
	scanf("%d %d", &operatorOne, &operatorTwo);

	if (!strcmp(operation,"add"))
	{
		printf("%s: %d\n",message[2], add(operatorOne, operatorTwo) );
	}
	else if (!strcmp(operation,"substract"))
	{
		printf("%s: %d\n",message[2], substract(operatorOne, operatorTwo) );
	}
	else{
		printf("%s\n", message[1]);
	}

	
	return 0;
}