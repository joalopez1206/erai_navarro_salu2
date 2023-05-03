#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "inv_perm.h"
typedef struct {
    int *l;
    int N;
} ListArray;

void inv_perm(int *l, int N, int *out){
    for(int i = 0; i<N; i++){
        out[l[i]] = i;
    }
}
void test_2(){
    int N = 4;
    int l[] = {1,3,5,7};
    int *l_1 = malloc(N*sizeof(int));
    inv_perm(l, N, l_1);
    print_lst(l, N);
    print_lst(l_1, N);
}