#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void print_lst(int *l, int n){
    printf("[");
    for(int i = 0; i <n-1; i++){
        printf("%d, ",l[i]);
    }
    printf("%d]\n", l[n-1]);
}