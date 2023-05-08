#include <cstdio>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;

typedef struct pair {
  int pi;
  int i;
} Pair;

Pair *createArrayOfPairs(int *array, int N) {
  Pair *pairs = (Pair *)malloc(sizeof(Pair)*N);
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

class compFirst {
public:
    int operator() (Pair p1, Pair p2) {
        return p1.pi > p2.pi;
    }
};

void mergesort(Pair *pairs, int left, int right, int d, int N){
  if (left < right) {
    int range = N/d;
    for(int i = 0; i<d; i++){
      mergesort(pairs, left+range*i, left+range*(i+1)-1, d, range);
    }

    // Implementar el merge();
    // merge(pairs, left, range, right);
  }
}

void merge(Pair *pairs, int left, int right, int d, int N) {
  priority_queue <Pair, vector<Pair>, compFirst > heap;
  // EJEMPLO PURAMENTE PARA VER QUE ORDENA SEGUN LA PRIMERA COMPONENTE
  heap.push(pairs[3]);
  heap.push(pairs[1]);
  heap.push(pairs[2]);
  heap.push(pairs[0]);
  while (!heap.empty()) {
    Pair p = heap.top();
    cout << "(" << p.pi << ", " << p.i << ")\n";
    heap.pop();
  }
}

int main(){
    int l1[] = {2,3,1,4};
    Pair *pairs = createArrayOfPairs(l1, 4);
    print_pairs(pairs, 4);
    merge(pairs, 1,1,1,1);
    free(pairs);
    return 0;
}
