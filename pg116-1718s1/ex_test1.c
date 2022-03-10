#include<stdio.h>
#include<stdlib.h>
#include "./ex1.h"



  
int main(int argc, char** argv){
   struct array* tab=(struct array*)malloc(sizeof(struct array));
   for(int i=0;i<CAPACITY;i++){
     tab->a[i]=88;
   }
   tab->size=6789;
   tab->first=NULL;
   //display(tab);
   array__empty(tab);
   display(tab);
   array__push_front(tab,1);
   array__push_front(tab,2);
   array__push_front(tab,3);
   array__push_front(tab,4);
   display(tab);
   array__pop_front(tab);
   array__pop_front(tab);
   display(tab);
   array__push_back(tab,4);
   display(tab);
   array__push_back(tab,5);
   display(tab);
   array__pop_back(tab);
   display(tab);
   array__pop_back(tab);
   display(tab);
   array__push_front(tab,1);
   array__push_back(tab,2);
   array__push_back(tab,3);
   array__push_front(tab,4);
   display(tab);
   printf("TOP FRONT: %d -- ###TOP BACK: %d\n",array__front(tab),array__back(tab));
   array__pop_back(tab);
   array__pop_front(tab);
   array__pop_front(tab);
   array__pop_back(tab);
   display(tab);
   printf("TOP FRONT: %d -- ###TOP BACK: %d\n",array__front(tab),array__back(tab));
   free(tab);
   return 0;
 }

