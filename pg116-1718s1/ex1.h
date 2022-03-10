#ifndef __ARRAY___
#define __ARRAY___
#define CAPACITY 5
struct array {
  int a[CAPACITY];   // tableau d'entier
  int * first;       // pointeur sur 1er élément
  size_t size;       // nombre d'éléments stockés dans a
};

size_t array__size(struct array const * array);
void array__empty(struct array * array);
 int array__push_front(struct array * array, int x);
int array__pop_front(struct array * array);
  int array__front(struct array const * array);
 int array__push_back(struct array * array, int x);
  int array__pop_back(struct array * array);
  int array__back(struct array const * array);
void display(struct array* t);
#endif
