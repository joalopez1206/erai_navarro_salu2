#pragma once
#define REP 10
typedef struct pair {
  long pi;
  long i;
} Pair;

struct Node {
	long pi;
  long i;
	Node *next;
};
struct Node *mergeD(Pair *pairs, long left, long d, long N);
Pair *createArrayOfPairs(long *array, long N);
void print_lst(long *l, long n);
long *generate_n_random_perm(long n);
void check_order(long *array, long* inverse_array, long size);
long *generate_n_random_perm_from_one(long n);