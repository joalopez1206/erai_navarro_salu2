#include <cstdio>
#include <cstdlib>
#include "utils.h"

void print_lst(long *l, long n){
    printf("[");
    for(long i = 0; i <n-1; i++){
        printf("%d, ",l[i]);
    }
    printf("%d]\n", l[n-1]);
}

long *generate_n_random_perm(long n){
    long *retval =(long *) malloc(n * sizeof(long));

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

void check_order(long *array, long* inverse_array, long size){
    for(long j = 0; j<size; j++){
        if (!(array[inverse_array[j]] == j)){
            printf("Error! Array val = %d and actual val = %d\n", array[inverse_array[j]], j);
            exit(0);
        }
    }
}

Pair *createArrayOfPairs(long *array, long N) {
  Pair *pairs = (Pair *)malloc(sizeof(Pair)*N);
  for (long i = 0; i < N; i++) {
    pairs[i].pi = array[i];
    pairs[i].i = i+1;
  }
  return pairs;
}

long *generate_n_random_perm_from_one(long n){
    long *retval =(long *) malloc(n * sizeof(long));

    for(long i = 1; i<=n; i++){
        retval[i-1] = i; 
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