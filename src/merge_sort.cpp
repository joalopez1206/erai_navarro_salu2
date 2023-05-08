#include <cstdio>
#include <cstdlib>
#include "utils.h"
#include "merge_sort.h"

//esto es para hacer un merge desde el indice [i..j] y [j+1..k]
void merge(long *l, long i, long j, long k) {
    long izq = j-i+1, der = k-(j+1)+1;
    long *l_izq =(long *) malloc(izq*sizeof(long));
    long *l_der =(long *) malloc(der*sizeof(long));
    for(long a = 0; a<izq; a++){
        l_izq[a] = l[i+a];
    }
    for(long a = 0; a< der; a++){
        l_der[a] = l[j+1+a];
    }
    long left_so_far = 0, right_so_far = 0;
    long m = i;
    while(left_so_far< izq && right_so_far<der){
        if(l_izq[left_so_far] < l_der[right_so_far]){
            l[m] = l_izq[left_so_far];
            left_so_far++;
        }
        else{
            l[m] = l_der[right_so_far];
            right_so_far++;
        }
        m++;
    }

    while(left_so_far<izq){
        l[m] = l_izq[left_so_far];
        left_so_far++; 
        m++;
    }

    while(right_so_far<der){
        l[m] = l_der[right_so_far];
        right_so_far++;
        m++;
    }
    free(l_izq); free(l_der);
}

void merge_sort(long *arr, long l, long r) {
    if (l < r) {
        long m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void test_funcionalidad(){
    printf("Tests for mergeSort\n");
    long N=6;
    long l[] = {3,8,1,4,5,2};
    merge_sort(l, 0, N-1);
    print_lst(l, N);
}

void test_maldito(){
    printf("Test para mergesort\n");
    for(int i = 0; i<30; i++){
        //generamos un arreglo al azar de tamaño 2**i
        long size = 1L<<i;
        long *array  = generate_n_random_perm(size);
        merge_sort(array,0 , size-1);
        for(long j = 0; j<size; j++){
            if (!array[j]== j){
                printf("Error! Array val = %d and actual val = %d\n", array[j], j);
                exit(0);
            }
        }
        printf("\rOK for 2^%d",i);
        fflush(stdout);
        free(array);
    }
}