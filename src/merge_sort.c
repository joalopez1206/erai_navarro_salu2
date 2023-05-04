#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "merge_sort.h"


void my_merge(int *l1, int *l2, size_t l1_len, size_t l2_len, int* out) {
    //nothin
}

void mergesort(int *l, int N){
    
}
void test_1(){
    int len_l1 = 4, len_l2 = 6;
    int len_l = len_l1 + len_l2;
    int l1[] = {1,3,5,7};
    int l2[] = {2,4,6,8,10,12};
    print_lst(l1, len_l1);
    print_lst(l2, len_l2);
    int *l = malloc((len_l1+len_l2)*sizeof(int));
    my_merge(l1,l2, len_l1, len_l2, l);
    print_lst(l, len_l);
    free(l);
}