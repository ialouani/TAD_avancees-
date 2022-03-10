#include<assert.h>

#include<stdio.h>
#include<stdlib.h>
#include "link.h"

//struct dequeue;//tests fonctionnelles=>type incomplet pas grave.
//pas de presence en compilation ; interpretation en void*:::l'ecriture
//en type incomplet est en coeur meme des optimisations de l'abstraction
//totalement inutile.
struct dequeue{
  struct link* l;
  };


struct dequeue * dequeue__empty();
int dequeue__is_empty(struct dequeue const * dequeue);
int dequeue__front(struct dequeue const * dequeue);
size_t dequeue__size(struct dequeue const * dequeue);
void dequeue__free(struct dequeue * dequeue);
int dequeue__push_front(struct dequeue * dequeue, int x);
  
static void test_API_doublequeue__ATall(){
  struct dequeue* empty_double_queue=dequeue__empty();
  assert(dequeue__is_empty(empty_double_queue)==1);
  dequeue__push_front(empty_double_queue,1);
  assert(dequeue__is_empty(empty_double_queue)==0);
  assert(dequeue__front(empty_double_queue)==1);
  display(empty_double_queue->l->head->array);
  assert(dequeue__is_empty(empty_double_queue)==0);//ajoute pour rien...
  dequeue__push_front(empty_double_queue,2);
  display(empty_double_queue->l->head->array);
  assert(dequeue__size(empty_double_queue)==2);
  display(empty_double_queue->l->head->array);
  assert(dequeue__front(empty_double_queue)==2);
  dequeue__push_front(empty_double_queue,3);
  display(empty_double_queue->l->head->array);
  //(!tests structurels..(les 2 tests sont <=>()///).//////////
  //ni unitaires en structure).
  //on est oblige pour convaincre le lecteur.
  //EH voilà!!
  //ca sert AUSSI(arguments) a mixer les deux approches pour
  //une verification complete dependante de la structure
  //tout en ayant un display(set_debug_data) naturellement
  //present dans la plupart des fonctions algorithmiques
  //traitant les primitives des tad(s)...
  assert(dequeue__front(empty_double_queue)==3);
  assert(dequeue__size(empty_double_queue)==3);
  dequeue__push_front(empty_double_queue,4);
  dequeue__push_front(empty_double_queue,5);
  display(empty_double_queue->l->head->array);
  display(empty_double_queue->l->head->next->array);
  dequeue__push_front(empty_double_queue,6);
  
  assert(dequeue__front(empty_double_queue)==6);
  assert(dequeue__size(empty_double_queue)==6);
  dequeue__push_front(empty_double_queue,7);
  display(empty_double_queue->l->head->next->next->array);
  display(empty_double_queue->l->head->next->array);
  display(empty_double_queue->l->head->array);
  dequeue__push_front(empty_double_queue,8);
  assert(dequeue__front(empty_double_queue)==8);
  assert(dequeue__size(empty_double_queue)==8);
  display(empty_double_queue->l->head->array);
  display(empty_double_queue->l->head->next->array);
  display(empty_double_queue->l->head->next->next->array);
  dequeue__free(empty_double_queue);
}


int main(int argc, char** argv){
  test_API_doublequeue__ATall();
  puts("TOUT EST OK ; <>FIN/ SESSION1: PG116(2017-2018).///");
  return 0;
}
//remarques sur les fautes:
//allocation des array car une allocation d'un struct element vu que l'interieur contient non pas un tableau ou simplement un stockage facile d'un int* mais un struct array* donc la plupart des cas le malloc est comme alloc ne se fatigue pas pour remonter aux champs=>initialisation vide (array==NULL)
//=>pour acceder via array__empty(head->array) avec head==dequeue->l->head
//il faudrait savoir ce que contient head->array => il faudrait apres allocation de dequeue changer sa valeur (la valeur de double_empty__queue.l->head->array) via une allocation de ce array DE TYPE( a ne pas confondre avec un objet de type int[]) ; c/c:::: allocation dynamique de chaque ss tableau est primordiale.

//apres les nons sont differents dans les structures de controle et le size qui retourne une valeur size_t doit tester si llm__next(head) qui retourne head->next (a ne pas confondre avec lnl__first(struct link*) qui retourne le premier struct lelement* dans la liste doublement chainee soit: l->head. Donc, il faudrait faire a la fin vu que tail est neglige dans le parcours final+ la commande triviale: len+=array__size(head->array(de type struct array*)) pour avoir la longueur du dernier tableau pointee par dequeue->l->tail(car contient le champ *array).
