#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int k; 
    scanf("%d %d",&n,&k);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    
    //int *b = malloc(sizeof(int) * n);

    for(int f=0; f < k; f++){
    int primero = a[0];
    for(int i = 0; i < n; i++){
        a[i] = a[i + 1];
    }

    a[n -1] = primero;
    }

    for(int l=0; l<n;l++){
        printf("%d ", a[l]);
    }

    printf("\n");

    return 0;
   
}
