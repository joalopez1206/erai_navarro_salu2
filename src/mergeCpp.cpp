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
// struct Node {
// 	Pair pair;
// 	Node *next;
// };

struct Node* newNode(Pair pair) {
	struct Node* new_node = new Node();
	new_node->pi = pair.pi;
  new_node->i = pair.i;
	new_node->next = NULL;

	return new_node;
}

// 'compare' function used to build
// up the priority queue
struct compare {
	bool operator()(
		struct Node* a, struct Node* b) {
		return a->pi > b->pi;
	}
};

Pair *createArrayOfPairs(int *array, int N) {
  Pair *pairs = (Pair *)malloc(sizeof(Pair)*N);
  for (int i = 0; i < N; i++) {
    // pairs[i] = {array[i], i};
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

class compFirst {
public:
    int operator() (Pair p1, Pair p2) {
        return p1.pi > p2.pi;
    }
};

Pair *getSubArray(Pair *pairs, int l, int range) {
  //Pair mmm[range];
  Pair *mmm = (Pair *)malloc(sizeof(Pair)*range);
  for (int i = 0; i<range; i++) {
    mmm[i] = pairs[l+i];
  }
  return mmm;
}
struct Node *mergeD(Pair *pairs, int left, int d, int N);
void printList(struct Node* head);

void mergesort(Pair *pairs, int left, int right, int d, int N){
  if (left < right) {
    int range = N/d;
    for(int i = 0; i<d; i++){
      mergesort(pairs, left+range*i, left+range*(i+1)-1, d, range);
    }

    // Implementar el merge();
    struct Node * jeje = mergeD(pairs, left, d, range);
    printList(jeje);
  }
}

// void merge(Pair *pairs, int left, int right, int d, int N) {
//   priority_queue <Pair, vector<Pair>, compFirst > heap;
//   // EJEMPLO PURAMENTE PARA VER QUE ORDENA SEGUN LA PRIMERA COMPONENTE
//   heap.push(pairs[3]);
//   heap.push(pairs[1]);
//   heap.push(pairs[2]);
//   heap.push(pairs[0]);
//   while (!heap.empty()) {
//     Pair p = heap.top();
//     cout << "(" << p.pi << ", " << p.i << ")\n";
//     heap.pop();
//   }
// }
// priority_queue <Pair, vector<Pair>, compFirst > heap;

// void merge(Pair *pairs, int left, int right, int d, int N) {
//   // int n1 = N - left + 1;
//   // int n2 = right - N;
//
//   // int listOfLength[d];
//   // for (int i = 0; i<d; i++) {
//   //   listOfLength[i] = left+N*i
//   // }
//   // d listas de tamaño N
//   // Pair tempArrays[d][N];
//   // for (int i = 0; i<d; i++) {
//   //   // for (int j = 0; j<N; j++) {
//   //     // printf("(%d, %d)\n", pairs[left+i].pi, pairs[left+i].i);
//   //     tempArrays[i] = getSubArray(pairs, left, N);
//   //   // }
//   // }
//   // for (int m = 0; m<d; m++) {
//   //   for (int n = 0; n<N; n++) {
//   //     heap.push(tempArrays[m][n]);
//   //   }
//   // }
//   int listOfIndexes[d];
//   for (int i = 0; i<d; i++) {
//     listOfIndexes[i] = left+N*i;
//   }
//   // for (int m = 0; m<d; m++) {
//   //   // for (int n = 0; n<N; n++) {
//   //     heap.push(pairs[listOfIndexes[m]]);
//   //   // }
//   // }
//   // for (int i = 0; i<d; i++) {
//   //   heap.push(pairs[left+N*i])
//   // }
//   // for (int k = 0; k<d; k++) {
//   //   pairs[k] = heap.top();
//   //   heap.pop();
//   // }
//
//   // while (!heap.empty()) {
//   for (int m = 0; m<d; m++) {
//     // for (int n = 0; n<N; n++) {
//       heap.push(pairs[listOfIndexes[m]]);
//       listOfIndexes[m]++;
//     // }
//   }
//   int space = 0;
//   do {
//     Pair top = heap.top();
//     printf("(%d, %d)\n", top.pi, top.i);
//     pairs[left+space] = top;
//     heap.pop();
//     Pair min = pairs[listOfIndexes[0]];
//     int pp = 0;
//     for(int p=1; p<d;p++) {
//       Pair mmm = pairs[listOfIndexes[p]];
//       if (mmm.pi<min.pi) {
//         min=mmm;
//         pp = p;
//       }
//     }
//     heap.push(min);
//     listOfIndexes[pp]++;
//     space++;
//   } while (!heap.empty());
//   // }
//   // while (!heap.empty()) {
//   //   Pair p = heap.top();
//   //   cout << "(" << p.pi << ", " << p.i << ")\n";
//   //   heap.pop();
//   // }
// }

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

	// Handles the case when k = 0
	// or lists have no elements in them
	if (heap.empty())
		return NULL;
  Pair ayuda = {0,0};
  struct Node *dummy = newNode(ayuda);
	struct Node *last = dummy;
  while (!heap.empty()) {
    struct Node* curr = heap.top();
		heap.pop();

    last->next = curr;
		last = last->next;

    if (curr->next != NULL)

		heap.push(curr->next);
  }
  // for (int i = 0; i < d; i++) {
	// 	Node* temp = *(head + i);
  //
	// 	// Linked list number
	// 	cout << i << "-->\t";
  //
	// 	// Print the Linked List
	// 	while (temp != NULL) {
	// 		printf("(%d, %d) ", temp->pi, temp->i);
	// 		temp = temp->next;
	// 	}
  //
	// 	cout << '\n';
	// }
  struct Node *estePues = dummy;
  for (int mm = 0; mm<N; mm++) {
    printf("N es: %d\n", N);
    estePues=estePues->next;
    pairs[left+mm].pi = estePues->pi;
    printf("el par agregado fue: (%d, %d) \n", pairs[left+mm].pi, pairs[left+mm].i);
    pairs[left+mm].i = estePues->i;
  }
  // printf("ASI QUEDO\n");
  // print_pairs(pairs, 4);
  return dummy->next;
}

void printList(struct Node* head) {
  while (head != NULL) {
      printf("(%d, %d) ", head->pi, head->i);
      head = head->next;
  }
  cout << endl;
}

int main(){
    // int l1[] = {2,3,1,4};
    // Pair *pairs = createArrayOfPairs(l1, 4);
    // print_pairs(pairs, 4);
    // merge(pairs, 1,1,1,1);
    //int l1[] = {3,4,1,2,6,5,7,8};
    // int l1[] = {5,6,7,8,1,2,3,4};
    int l1[] = {4,3,1,2};
    //int l1[] = {2,1};
    // print_no_pairs(l1, 4);
    Pair *pairs = createArrayOfPairs(l1, 4);
    print_pairs(pairs, 4);
    mergesort(pairs, 0, 3, 2, 4);
    // mergeD(pairs, 2, 4);
    // printList(head);

    // print_pairs(pairs, 4);
    int *noPairs = killPairs(pairs, 4);
    // print_no_pairs(noPairs, 4);
    free(pairs);
    free(noPairs);
    return 0;
}
