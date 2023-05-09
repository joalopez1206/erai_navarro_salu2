#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <queue>
#include "utils.h"
#include "merge_sort.h"

using namespace std;
using namespace std::chrono;
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
    printf("Tests for mergesort para arreglo [2,1,0,5,3,4,7,6]\n");
    long N=8;
    long l[] = {2,1,0,5,3,4,7,6};
    merge_sort(l, 0, N-1);
    print_lst(l, N);
}

void test_maldito(){
    printf("Test para mergesort aleatorio\n");
    for(int i = 18; i<28; i++){
        //generamos un arreglo al azar de tamaño 2**i
        long size = 1L<<i;
        vector<microseconds> times(REP);
        for(int k = 0; k<REP; k++){
            long *array  = generate_n_random_perm(size);
            auto start = high_resolution_clock::now();
            merge_sort(array,0 , size-1);
            auto stop = high_resolution_clock::now();
            for(long j = 0; j<size; j++){
                if (!array[j]== j){
                    printf("Error! Array val = %d and actual val = %d\n", array[j], j);
                    exit(0);
                }
            }
            auto duration = duration_cast<microseconds>(stop - start);
            times[k] = duration;
            free(array);
        }
        microseconds s = microseconds(0);
        for (auto &&time : times){
            s = s + time;
        }
        microseconds mean = s/REP;
        printf("OK for 2^%d ---> %d microseconds\n", i, mean);
        fflush(stdout);
    }
}