#include <cstdio>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;

typedef struct pair {
  int pi;
  int i;
} Pair;

struct Node {
	int pi;
  int i;
	Node *next;
};

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

Pair *createArrayOfPairs(int *array, int N) {
  Pair *pairs = (Pair *)malloc(sizeof(Pair)*N);
  for (int i = 0; i < N; i++) {
    pairs[i].pi = array[i];
    pairs[i].i = i+1;
  }
  return pairs;
}

int *killPairs(Pair *pairs, int N) {
  int *noPairs = (int *)malloc(sizeof(int)*N);
  for (int i = 0; i<N; i++) {
    noPairs[i] = pairs[i].i;
  }
  return noPairs;
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

void print_no_pairs(int *noPairs, int N){
  int i = 0;
    printf("[");
    do {
      printf("%d, ", noPairs[i]);
      i++;
    } while (i<N-1);
    printf("%d]\n", noPairs[i]);
}

struct Node *mergeD(Pair *pairs, int left, int d, int N);
void printList(struct Node* head);

void mergesort(Pair *pairs, int left, int right, int d, int N){
  if (left < right) {
    int range = N/d;
    for(int i = 0; i<d; i++){
      if (d>range) {
        mergesort(pairs, left+range*i, left+range*(i+1)-1, range, range);
      } else {
        mergesort(pairs, left+range*i, left+range*(i+1)-1, d, range);
      }
    }
    struct Node * jeje = mergeD(pairs, left, d, range);
  }
}

struct Node *mergeD(Pair *pairs, int left,int d, int N) {
  priority_queue<Node*, vector<Node*>, compare> heap;
  Node** head;

	head = new Node*[d];

	for (int k = 0; k < d; k++) {
		*(head + k) = NULL;
	}
  int mmm = 0;
  for (int i = 0; i < d; i++) {

		Node* prev = NULL;

    for(int j = 0; j<N; j++) {
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
  for (int i = 0; i < d; i++)
		if (head[i] != NULL)
			heap.push(head[i]);

	if (heap.empty())
		return NULL;
  Pair pair = {0,0};
  struct Node *dummy = newNode(pair);
	struct Node *last = dummy;
  int index = 0;
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
  return dummy->next;
}

int main(){
    int l1[] = {8,7,6,5,4,3,2,1};
    Pair *pairs = createArrayOfPairs(l1, 8);
    print_pairs(pairs, 8);
    mergesort(pairs, 0, 7, 2, 8);
    print_pairs(pairs, 8);
    int *noPairs = killPairs(pairs, 8);
    free(pairs);
    free(noPairs);
    return 0;
}
