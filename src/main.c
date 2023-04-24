#include <stdio.h>
#include <stdlib.h>

int* my_merge(const int *l1, const int *l2, int N);

int* my_merge(const int *l1, const int *l2, int N) {
    int *retlst = malloc(sizeof(int) * N);
    int j = 0,k=0;
    for(int i =0; i<2*N; i++){
        if(l1[j]<l2[k]){
            retlst[i] = l1[j];
            j++;
        }
        else{
            retlst[i] = l2[k];
            k++;
        }
    }
    return retlst;
}

void* print_lst(int *l, int n){
    printf("[");
    for(int i = 0; i <n; i++){
        printf("%d ",l[i]);
    }
    printf("]\n");
}

int main(){
    int l1[] = {1,3,5,7};
    int l2[] = {2,4,6,8};
    print_lst(l1,4);
    print_lst(l2, 4);
    int *new_lst = my_merge(l1,l2,4);
    print_lst(new_lst, 8);
}