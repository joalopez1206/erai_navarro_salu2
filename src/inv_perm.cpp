#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <vector>
#include "utils.h"
#include "inv_perm.h"
using namespace std;
using namespace std::chrono;
void inv_perm(long *l, long N, long *out){
    for(long i = 0; i<N; i++){
        out[l[i]-1] = i+1;
    }
}

void test_simple(){
    printf("Test Simple arreglo 3 1 0 2\n");
    long N = 4;
    long l[] = {3,1,4,2};
    long *l_1 = (long *) malloc(N*sizeof(long));
    inv_perm(l, N, l_1);
    print_lst(l, N);
    print_lst(l_1, N);
    long *l_idem = (long *)malloc(N*sizeof(long));
    for(long i = 0; i<N; i++){
        l_idem[i] = l[l_1[i]];
    }
    print_lst(l_idem, N);
}



void test_azaroso(){
    printf("Test azaroso\n");
    for(int i = 19; i<28; i++){
        //generamos un arreglo al azar de tamaño 2**i
        long size = 1L<<i;
        vector<microseconds> times(REP);
        for(int j = 0; j<REP; j++){
            long *array  = generate_n_random_perm(size);
            long *inverse_array = (long *)malloc(size*sizeof(long));
            auto start = high_resolution_clock::now();
            inv_perm(array, size, inverse_array);
            auto stop = high_resolution_clock::now();
            check_order(array, inverse_array, size);
            auto duration = duration_cast<microseconds>(stop - start);
            times[j] = duration;
            free(array); free(inverse_array);
        }
        microseconds s = microseconds(0);
        for (auto &&time : times){
            s = s + time;
        }
        microseconds mean = s/REP;
        
        printf("OK for 2^%d ---> %d microseconds\n",i, mean);
        fflush(stdout);
    }
}