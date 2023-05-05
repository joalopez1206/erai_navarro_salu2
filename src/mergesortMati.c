#include <stdio.h>
#include <stdlib.h>

typedef struct pair {
  int pi;
  int i;
} Pair;

Pair *createArrayOfPairs(int *array, int N) {
  Pair *pairs = malloc(sizeof(Pair)*N);
  for (int i = 0; i < N; i++) {
    // pairs[i] = {array[i], i};
    pairs[i].pi = array[i];
    pairs[i].i = i+1;
  }
  return pairs;
}

void print_pairs(Pair *pairs, int N){
  int i = 0;
    printf("[");
    do {
      printf("(%d, %d) ", pairs[i].pi, pairs[i].i);
      i++;
    } while (i<N-1);
    printf("(%d, %d)]\n", pairs[i].pi, pairs[i].i);
}

void mergesort(Pair *pairs, int left, int right, int d){
  if (left < right) {
    int length = (right - left) / d;
    int i = 0;
    // if ((right-left)%2==0) {
    //   do {
    //     mergesort(pairs, left+length*i, left+length*(i+1)-1, d);
    //     i++;
    //   } while (i<d-1);
    //   mergesort(pairs, left+length*i, left+length*(i+1), d);
    // } else {
    //   while (i<d) {
    //     mergesort(pairs, left+length*i, left+length*(i+1)-1, d);
    //     i++;
    //   }
    // }

    // if ((right-left)%2==0) {
    //   do {
    //     mergesort(pairs, left+length*i, left+length*(i+1)-1, d);
    //     i++;
    //   } while (i<d-1);
    //   mergesort(pairs, left+length*i, left+length*(i+1), d);
    // } else {
    //   mergesort(pairs, left+length*i, left+length*(i+1), d);
    //   i++;
    //   while (i<d) {
    //     mergesort(pairs, left+length*i+1, left+length*(i+1)+1, d);
    //     i++;
    //   }
    // }

    if ((right-left)%d==0) {
      length = (right-left)/d;
    } else {
      length = (right-left)/d + 1;
    }

    do {
      mergesort(pairs, left+length*i, left+length*(i+1)-1, d);
      i++;
    } while (i<d-1)
    mergesort(pairs, left+length*i, right, d);

    // falla para d=4, con l=0 y r=5, length queda 2 y los intervalos
    // van quedando [0, 1], [2, 3], [4, 5] y falta el último intervalo

    // Implementar el merge();
    merge(pairs, left, length, right);
  }
}


int main(){
    int l1[] = {1,3,5,7};
    Pair *pairs = createArrayOfPairs(l1, 4);
    print_pairs(pairs, 4);
    free(pairs);
    return 0;
}
