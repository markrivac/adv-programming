#include <stdio.h>
#include <unistd.h>

int main(){
    int pid;
    pid = fork();
    if(pid == 0){
        execl("/Applications/Calculator.app/Contents/MacOS/Calculator", "Calculator", (char*)0);
        printf("Proceso Hijo\n");
    }else{
        printf("Proceso Padre");
    }
    return 0;
}