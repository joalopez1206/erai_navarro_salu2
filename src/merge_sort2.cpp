#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <queue>
#include "utils.h"
#include "merge_sort2.h"

using namespace std;
using namespace std::chrono;


struct Node* newNode(Pair pair) {
	struct Node* new_node = new Node();
	new_node->pi = pair.pi;
  new_node->i = pair.i;
	new_node->next = NULL;

	return new_node;
}

struct compare {
	bool operator()(
		struct Node* a, struct Node* b) {
		return a->pi > b->pi;
	}
};

long *killPairs(Pair *pairs, long N) {
  long *noPairs = (long *)malloc(sizeof(long)*N);
  for (long i = 0; i<N; i++) {
    noPairs[i] = pairs[i].i;
  }
  return noPairs;
}

void print_pairs(Pair *pairs, long N){
  long i = 0;
    printf("[");
    do {
      printf("(%d, %d) ", pairs[i].pi, pairs[i].i);
      i++;
    } while (i<N-1);
    printf("(%d, %d)]\n", pairs[i].pi, pairs[i].i);
}

void print_no_pairs(long *noPairs, long N){
  long i = 0;
    printf("[");
    do {
      printf("%d, ", noPairs[i]);
      i++;
    } while (i<N-1);
    printf("%d]\n", noPairs[i]);
}



void mergesort(Pair *pairs, long left, long right, long d, long N){
  if (left < right) {
    long range = N/d;
    for(long i = 0; i<d; i++){
      if (d>range) {
        mergesort(pairs, left+range*i, left+range*(i+1)-1, range, range);
      } else {
        mergesort(pairs, left+range*i, left+range*(i+1)-1, d, range);
      }
    }
    struct Node * jeje = mergeD(pairs, left, d, range);
  }
}

struct Node *mergeD(Pair *pairs, long left,long d, long N) {
  priority_queue<Node*, vector<Node*>, compare> heap;
  Node** head;

	head = new Node*[d];

	for (long k = 0; k < d; k++) {
		*(head + k) = NULL;
	}
  long mmm = 0;
  for (long i = 0; i < d; i++) {

		Node* prev = NULL;

    for(long j = 0; j<N; j++) {
      Node* n = new Node;

      n->pi = pairs[left+mmm].pi;
      n->i = pairs[left+mmm].i;
      mmm++;
      n->next = NULL;

      if (*(head + i) == NULL) {
				*(head + i) = n;
			}
			else {
				prev->next = n;
			}
			prev = n;
		}
	}
  for (long i = 0; i < d; i++)
		if (head[i] != NULL)
			heap.push(head[i]);

	if (heap.empty())
		return NULL;
  Pair pair = {0,0};
  struct Node *dummy = newNode(pair);
	struct Node *last = dummy;
  long index = 0;
  while (!heap.empty()) {
    struct Node* curr = heap.top();
    pairs[left+index].pi = curr->pi;
    pairs[left+index].i = curr->i;
    index++;
		heap.pop();
    last->next = curr;
		last = last->next;
    if (curr->next != NULL) {
      heap.push(curr->next);
    }
  }
  delete[] head;
  return dummy->next;
}

void test_funcionalidad(){
    long d = 4;
    printf("Tests for mergesort para arreglo [2,1,8,5,3,4,7,6]\n");
    long N=8;
    long l[] = {2,1,8,5,3,4,7,6};
    Pair* lista_pair = createArrayOfPairs(l,N);
    mergesort(lista_pair, 0, N-1, d, N);
    print_no_pairs(killPairs(lista_pair,N),N);
}

void test_maldito(){
    printf("Test para mergesort aleatorio\n");
    for(int i = 4; i<19; i++){
        //generamos un arreglo al azar de tamaño 2**i
        long size = 1L<<i;
        vector<microseconds> times(REP);
        for(int k = 0; k<REP; k++){
            long *array  = generate_n_random_perm_from_one(size);
            auto start = high_resolution_clock::now();
            auto arrayPairs = createArrayOfPairs(array,size);
            mergesort(arrayPairs, 0 , size-1, 4, size);
            auto stop = high_resolution_clock::now();
            long *invperm = killPairs(arrayPairs, size);
            free(arrayPairs);
            for(long j = 1; j<=size; j++){
              if (!(array[invperm[j-1]-1] == j)){
                printf("Error! Array val = %d and actual val = %d\n", array[invperm[j-1]-1], j);
                exit(0);
              }
            }
            auto duration = duration_cast<microseconds>(stop - start);
            times[k] = duration;
            free(array); free(invperm);
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