#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
    cout << "Ingresa la cantidad de casos que necesitas calarle: ";
    int cantidadDeCasos;
    scanf("%i", &cantidadDeCasos);
    for (int i = 1; i <= cantidadDeCasos; i++){
        string palabraInicial;
        cin >> palabraInicial;
        string lastWord = "";
        for (int i = 0; i < palabraInicial.size(); i++){
            char caracter = palabraInicial[i];
            if (!lastWord.empty() && caracter >= lastWord[0]){
                lastWord = caracter + lastWord;
            }
            else{
                lastWord = lastWord + caracter;
            }
        }
        cout << "Case #" << i << ": " << lastWord << endl;
    }
    return 0;
}
