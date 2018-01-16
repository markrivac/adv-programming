#include <stdio.h>

int main(){
   
    int arreglo[] = {1,2,3,4,5};
    int suma = 9;

    if (sizeof(arreglo)>=2)
    {

        for (int i = 0; i < sizeof(arreglo); ++i)
        {
            int temp = arreglo[i];

            if (temp < suma)
            {
                for (int j = i; j < sizeof(arreglo); ++j)
                {
                    int temp2 = arreglo[j];
                    if (temp + temp2 == suma)
                    {
                        printf("El valor 1 = %i, El valor 2 = %i\n", temp, temp2);
                        return 0;
                    }
                }
            }
        }
    }

    printf("No se pudo encontrar el valor %i\n", suma);
    return 0;
}
