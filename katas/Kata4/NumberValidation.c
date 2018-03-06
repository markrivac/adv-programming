#include <stdio.h>
#include <string.h>

int isValidNumber(char *value)
{
    int valuePosition = 0;
    int currentElement;
    int isFloat = 0;
    int expresionSize = strlen(value);
    int isExponential = 0;
    int commas = 0;
    int digitCounter;
    int IS_NOT_A_VALID_NUMBER = 0;
    int IS_A_VALID_NUMBER = 1;

    char valueAtPosition = value[valuePosition];

    if (valueAtPosition == '+' || valueAtPosition == '-')
    {
        valuePosition++;
    }

    while (valuePosition < expresionSize)
    {
        currentElement = (int)valueAtPosition;

        if (isANaturalNumber(valueAtPosition)){
            if (commas){
                if (digitCounter < 3){
                    digitCounter++;
                }
                else{
                    return IS_NOT_A_VALID_NUMBER;
                }
            }
        }
        else if (commas && digitCounter < 3){
            return IS_NOT_A_VALID_NUMBER;
        }
        else if (isDot(valueAtPosition) && !isFloat && !isExponential && valuePosition < (expresionSize - 1)){
            commas = 0;
            isFloat = 1;
        }
        else if (isExponentialSymbol(valueAtPosition) && !isExponential && valuePosition < (expresionSize - 1)){
            commas = 0;
            isExponential = 1;
            if (value[valuePosition+1] == '+' || value[valuePosition+1] == '-')
            {
                valuePosition++;
            }
        }
        else if (isComa(currentElement) && valuePosition < (expresionSize - 1) && !isExponential && !isFloat && valuePosition > 0){
            if (!commas && valuePosition < 4)
            {
                commas = 1;
            }
            digitCounter = 0;
        }
        else if (isSpace(currentElement)){
            break;
        }
        else{
            return IS_NOT_A_VALID_NUMBER;
        }
        valuePosition++;
    }

    if (valuePosition == expresionSize){
        return IS_A_VALID_NUMBER;
    }
    else{
        return IS_NOT_A_VALID_NUMBER;
    }
}

int isANaturalNumber(int currentElement){
    int diagonalAsciiValue = 47;
    int twoDotsAsciiValue = 58;

    if (currentElement > diagonalAsciiValue && currentElement < twoDotsAsciiValue){
        return 1;
    }else{
        return 0;
    }
}

int isDot(int currentElement){
    int dotAsciiValue = 46;
    if(currentElement == dotAsciiValue){
        return 1;
    }else{
        return 0;
    }
}
int isComa(int currentElement){
    int commaAsciiValue = 44;
    if(currentElement == commaAsciiValue){
        return 1;
    }else{
        return 0;
    }
}

int isSpace(int currentElement){
    int apaceAsciiValue = 32;
    if(currentElement == apaceAsciiValue){
        return 1;
    }else{
        return 0;
    }
}

int isExponentialSymbol(int currentElement){
    int exponentialAsciiValue = 101;
    if(currentElement == exponentialAsciiValue){
        return 1;
    }else{
        return 0;
    }
}

int main()
{
    char *possibleNumber;
    scanf("%s", possibleNumber);
    int result = isValidNumber(possibleNumber);
    if (result){
        printf("%s is a valid number", possibleNumber);
    }
    else{
        printf("%s is not a valid number :(", possibleNumber);
    }
    return 0;
}