#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void print_lst(long *l, long n){
    printf("[");
    for(long i = 0; i <n-1; i++){
        printf("%d, ",l[i]);
    }
    printf("%d]\n", l[n-1]);
}

long *generate_n_random_perm(long n){
    long *retval = malloc(n * sizeof(long));

    for(long i = 0; i<n; i++){
        retval[i] = i; 
    }

    for (long i = n-1; i >= 0; --i){
        //generate a random number [0, n-1]
        long j = rand() % (i+1);

        //swap the last element with element at random index
        long temp = retval[i];
        retval[i] = retval[j];
        retval[j] = temp;
    }
    return retval;
}