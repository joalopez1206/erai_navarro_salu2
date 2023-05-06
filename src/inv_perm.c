#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "inv_perm.h"
void inv_perm(long *l, long N, long *out){
    for(long i = 0; i<N; i++){
        out[l[i]] = i;
    }
}

void test_simple(){
    printf("Test Simple arreglo 3 1 0 2\n");
    long N = 4;
    long l[] = {3,1,0,2};
    long *l_1 = malloc(N*sizeof(long));
    inv_perm(l, N, l_1);
    print_lst(l, N);
    print_lst(l_1, N);
    long *l_idem = malloc(N*sizeof(long));
    for(long i = 0; i<N; i++){
        l_idem[i] = l[l_1[i]];
    }
    print_lst(l_idem, N);
}

void test_azaroso(){
    printf("Test azaroso\n");
    for(int i = 0; i<30; i++){
        //generamos un arreglo al azar de tamaño 2**i
        long size = 1L<<i;
        long *array  = generate_n_random_perm(size);
        long *inverse_array = malloc(size*sizeof(long));
        inv_perm(array, size, inverse_array);
        for(long j = 0; j<size; j++){
            if (!(array[inverse_array[j]] == j)){
                printf("Error! Array val = %d and actual val = %d\n", array[inverse_array[i]], i);
                exit(0);
            }
        }
        printf("OK for 2^%d\n",i);
        free(array); free(inverse_array);
    }
}