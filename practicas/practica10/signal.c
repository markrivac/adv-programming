#include <stdio.h>
#include <signal.h>

void receivesSignal(int sig){
    printf("HOLA MUNDO \n");
    printf("Recibí señal %d\n:", sig);
}

int main(){
    signal(SIGTERM, receivesSignal);
    while(1){

    }
    return 0;
}