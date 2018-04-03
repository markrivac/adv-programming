
int main()
{
    int cantidadDeCasos;
    printf("Ingresa la cantidad de casos que necesitas calarle: ");
	scanf("%i", &cantidadDeCasos);
    for (int i = 1; i <= cantidadDeCasos; i++)
    {
        char palabraInicial[100];
        scanf("%c", &palabraInicial);
        char *lastWord = "";

        for (int c = 0; palabraInicial[c] != '\0'; c++)
        {
            if (&lastWord != "" && c >= lastWord[0])
            {
                lastWord = c + lastWord;
            }
            else
            {
                lastWord = lastWord + c;
            }
        }
        printf("%s,%i,%s,%c","Case #",i,": ",&lastWord);
    }
    return 0;
}
