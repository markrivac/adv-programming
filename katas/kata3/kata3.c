#include <stdio.h>
#include <string.h>
int main()
{
    char *coordenadas;
    scanf("%s", coordenadas);
    int x = 0, y = 0;
    int makesCircle = 0;

    for (int i = 0; i < strlen(coordenadas); i++)
    {
        char direccion = coordenadas[i];
        if (direccion == 'U')
        {
            y++;
        }
        else if (direccion == 'D')
        {
            y--;
        }
        else if (direccion == 'L')
        {
            x--;
        }
        else if (direccion == 'R')
        {
            x++;
        }
    }

    if (!x && !y)
    {
        makesCircle = 1;
    }

    if (makesCircle)
    {
        printf("%s\n", "Yess");
    }
    else
    {
        printf("%s\n", "Nope");
    }
    return 0;
}
