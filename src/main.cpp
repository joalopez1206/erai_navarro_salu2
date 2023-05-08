#include <cstdio>
#include "inv_perm.h"
#include "merge_sort.h"
int main() {
    printf("\n----------Tests para mergesort-------------\n");
    //test_funcionalidad();
    //test_maldito();
    printf("\n-------------------------------------------\n");
    printf("\n----Tests para inversa permutacion---------\n");
    test_simple();
    test_azaroso();
    printf("\n-------------------------------------------\n");
    return 0;
}
