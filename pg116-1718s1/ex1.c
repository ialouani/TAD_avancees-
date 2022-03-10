/********* DEBUT DU CODE A NE PAS MODIFIER **********************/
#include <stdlib.h>
#include<stdio.h>
#include"ex1.h"





/**
 * Retourne le nombre d'éléments stockés.
 **/
size_t array__size(struct array const * array)
{
  return array->size;
}

/* RAPPEL : un array ne peut contenir QUE des entiers positifs ou
   nuls. */

/********** FIN DU CODE A NE PAS MODIFIER ***********************/

/* Mettre en œuvre les fonctions de array ci-dessous. */

/**
 * Initialise une structure array à vide.
 **/
void array__empty(struct array * array){
  array->size=0;
  //int data=array->a[CAPACITY/2];
  array->first=&array->a[CAPACITY/2];
  for(int i=0;i<CAPACITY;i++)
    array->a[i]=0;
  return;
}

/**
 * Ajoute x en tête,
 * retourne 0 en cas de succès et -1 en cas d'erreur.
 **/
int array__push_front(struct array * array, int x){
  //rappel de la struct: un tableau dresse a + un pointeur first + size_t size.
  if(x<0 || array->a[0]!=0) return -1;
  //pas de fonction testant si il existe.
  //pas de fonction testant si la struct est empty ce qui pourrait etre le cas.
  if(array->size==0){//vide et initialisee.
    array->size++;
    *array->first=x;
    array->a[(int)(CAPACITY/2)]=x;
    return 0;
  }
  else{
    //tableau pas vide et x>=0 ne se retrouvant pas ici.
    int* tmp=&array->a[0];int i=0;
    while(*(tmp+i)!=*array->first){
      i++;
    }
    //tmp[i]==*array->first
    int k=i-1;
    array->a[k]=x;
    array->first--;
    array->size++;
    return 0;
  }
}
  
/**
 * Retourne l'élément en tête ou -1 en cas d'erreur.
 **/
int array__front(struct array const * array){
  if(array->size==0) return -1;
  else return *array->first;
}


/**
 * Retire l'élement en tête, 
 * retourne 0 en cas de succès et -1 en cas d'erreur.
 **/
int array__pop_front(struct array * array){
  if(array->size==0) return -1;
  else if(array->size==1){//revient a dire que ca serait
    //par effet de bord un tableau vide.
    array__empty(array);
    return 0;
  }
  else{
    int* tmp=array->first;
    *tmp=0;
    array->first++;
    array->size--;
    return 0;
  }
}
  

/**
 * Ajoute x en queue, 
 * retourne 0 en cas de succès et -1 en cas d'erreur.
 **/
int array__push_back(struct array * array, int x){
  if(x<0) return -1;
  else if(array->size==0){
    return array__push_front(array,x);
  }
  else{//array->size>=1
    //au moins un element ; pas vide.
    //but du probleme: optimiser la complexite.
    int* tmp=&array->a[0];int j=0;
    while(*(tmp+j)!=*(array->first)) j++;
    //tmp[j]==*(array->first)
    size_t k=j;//en terme d'index.||
    while(k<CAPACITY && *(tmp+(int)k)!=0) k++;
    if(k>=CAPACITY && *(tmp+(int)k)!=0) return -1;
    else if(k<CAPACITY){
      //*(tmp+(int)k)==0
      *(tmp+(int)k)=x;
    }
    array->size++;
    return 0;
  }
}
    

/**
 * Retourne l'élément en queue ou -1 en cas d'erreur.
 **/
int array__back(struct array const * array){
  if(array->size==0) return -1;
  else if(array->size==1) return *array->first;
  else if(array->size==5) return array->a[4];//debordement d'indices(VALGRIND!!!)
  else{
  int* tmp=array->first;
  while(*tmp) tmp++;
  return *(--tmp);
  }
}

/**
 * Retire l'élement en tête, 
 * retourne 0 en cas de succès et -1 en cas d'erreur.
 **/
int array__pop_back(struct array * array){
  if(array->size==0) return -1;
  else if(array->size==1) return array__pop_front(array);
  *(array->first+(int)array->size-1)=0;
  array->size--;
  return 0;
}

void display(struct array* t){
  for(int i=0;i<CAPACITY;i++){
    printf("%d\t",t->a[i]);
  }
  printf("\n");
  printf("adresse pointant vers le debut: %p:%d\n",t->first,*t->first);
  printf("sizeof this array structure: %zu\n",t->size);
  return;
}


 
