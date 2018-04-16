#include <stdlib.h>
#include <stdio.h>

int findMovies(double flight_length, double* movies_length){

    for(int i = 0; i < sizeof(movies_length) - 1; i++){
        for(int j = i + 1; j < sizeof(movies_length); j++){
            if(movies_length[i] + movies_length[j] == flight_length){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    
    double flight_length = 240;
    double movies_length[] = {110, 60, 45, 105, 170};

    if(findMovies(flight_length, movies_length)){
        printf("YES! There are two movies you can watch\n");
    }else{
        printf("Nope! There are not two movies you can watch\n");
    }
    return 0;
}