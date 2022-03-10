
/********* DEBUT DU CODE A NE PAS MODIFIER **********************/
#include <stdlib.h>
#include<stdio.h>
#include "link.h"


struct dequeue {
  struct link * l;
};

/* RAPPEL : la dequeue ne peut contenir QUE des entiers positifs ou
   nuls. */

/********** FIN DU CODE A NE PAS MODIFIER ***********************/

/* Mettre en œuvre les fonctions de la dequeue ci-dessous, utilisant
   UNIQUEMENT les fonctions de `struct link` et `struct array`. */

//free=>allocation par retour d'adresse d'un type struct dequeue*.
  //*dq contient un pointeur vers *l qui permet d'avoir le 1er element
  //via dq->l->head qui est de type struct lelement* et qui encapsule
  //indirectement l'adresse des elements du tableau: dq->l->head->array.
  //acceder via une adresse pour lnk_empty() qui ne retourne pas
  //pour pouvoir allouer de nouveaux tableaux via la 1er reference~:
  //dq->l->**head** => allocation dynamique necessaire pour dq->l apres
  //dq.
/**
 * Retourne une dequeue vide.
 **/
struct dequeue * dequeue__empty(){
  struct dequeue *dq=(struct dequeue*)malloc(sizeof(*dq));
  dq->l=(struct link*)malloc(sizeof(*dq->l));
  *(dq->l)=lnk__empty();
  return dq;
}
  

/**
 * Retourne vraie si dequeue est vide sinon faux.
 **/
int dequeue__is_empty(struct dequeue const * dequeue){
  return lnk__first(dequeue->l)==NULL && lnk__last(dequeue->l)==NULL;
}

/**
 * Retourne l'élément en tête de dequeue et -1 en cas d'erreur.
 **/
int dequeue__front(struct dequeue const * dequeue){
  if(dequeue__is_empty(dequeue)) return -1;
  else{
    struct lelement* head=lnk__first(dequeue->l);
    return array__front(head->array);
  }
}
    

/**
 * Retourne le nombre d'éléments stockés.
 **/
size_t dequeue__size(struct dequeue const * dequeue){
  size_t len=0;
  if(dequeue__is_empty(dequeue)) return len;
  else{
    struct lelement* head=lnk__first(dequeue->l);
    while(llm__next(head)!=NULL){
      len+=array__size(head->array);
      head=llm__next(head);
    }
    len+=array__size(head->array);//attention;il faudrait ajouter celui-la.
    return len;
  }
}

/**
 * Libère la mémoire allouée pour la dequeue.
 **/
void dequeue__free(struct dequeue * dequeue){
  if(dequeue__is_empty(dequeue)){
    free(dequeue->l);free(dequeue);return;
  }
  else{
    struct lelement* head=lnk__first(dequeue->l);
    struct lelement* tmp;
    //    struct array* rry2;
    struct array* rry=head->array;
    while(!llm__is_end_mark(head)){
      tmp=llm__next(head);
      free(rry);//le fond d'abord (ce sont justedes remarques pour les lecteurs pour faciliter la comprehension).
      free(head);
      head=tmp;
      if(head!=NULL) rry=head->array;
    }
    free(dequeue->l);
    free(dequeue);
    return;
  }
}

/**
 * Ajoute x en tête de la dequeue,
 * retourne 0 en cas de succès et -1 en cas d'erreur.
 **/

//si dequeue est vide=>allocation memoire de head pour pouvoir
//decrire son contenu explicitement cest a dire le tableau en question.
int dequeue__push_front(struct dequeue * dequeue, int x){
  if(x<0) return -1;
  else if(dequeue__is_empty(dequeue)){
    struct lelement* head=(struct lelement*)malloc(sizeof(struct lelement));
    //il faut faire une gestion via dequeue->l avant seulement
    //=>utiliser lnk__add_head tout en rearrangeant son 2ieme parametre
    //alloue ici de type struct lelement*.
    //a l'allocation de head j'ai automatiquement une adresse (head) sur
    //la pile qui pointe vers un segment de donnee sur le tas
    //qui contient vu que array est le 1er champ l'espace necessaire au
    //stockage par incrementation de a soit dequeue->l->head->array(~).
    //reference obligatoirement par une adresse sur le tas.
    head->array=(struct array*)malloc(sizeof(struct array));
    array__empty(head->array);
  //initialisation car array_empty ne prend pas des dequeues 'vides'.(cad. en language formel(suivant ce contexte):NON INITIALISES)
    //(**)    array__empty(head->array);//modification par effet de bord du contenu (**).|||
    //qui sera a 99% des 0 (systeme brk/sbrk++ du TAS).
    //MAIS WARNING:
    //>>>head->array est bien mais pour acceder a ces champs aussi
    //ca pose probleme comme dequeue puis dequeue->l->head pour faire
    //au moins la 1ere manipulation de head->array->size=0;;
    //=>allocation? mais pas via les pages memoire du TAS.
    //RQ(astuce+moyen mnemotechnique): penser a ce qu'on a dit au debut de
    //l'enonce: tableau vide ### tableau non initialise.
    array__push_front(head->array,x);//ajout dans:: ((dequeue->l)->head)->array.
    //QUI VA contenir apres passage fonctionnel l'element x tout en
    //prenant compte du "curseur" first.//
    //mais head contient d'autres champs: (car de type struct lelement*) >>:::
    //2:-> !!next/prev!! , cela sera pris en compte dans les evaluations
    //suivantes.
    //pour en entre sur..
    //il faut faire: head->next=NULL & head->prev=NULL.
    struct lelement* next=llm__next(head);
    next=NULL;
    struct lelement* prev=llm__prev(head);
    prev=NULL;
    lnk__add_head(dequeue->l,head);
    //printf("1*********************");
    return 0;
  }
  else{
    //2 cas: soit dequeue->l->head->array est pleine: le pointeur first
    //est tout en bas: on atteind le maximum des array__push_front possibles
    //soit le contraire..(donc on reappliquera cette derniere suivant certaines
    //MISESa jour.///)
    struct lelement* head=lnk__first(dequeue->l);
    if(head->array->a[0]>0){
      struct lelement* head1=(struct lelement*)malloc(sizeof(struct lelement));
      head1->array=(struct array*)malloc(sizeof(struct array));
      array__empty(head1->array);
      array__push_front(head1->array,x);
      struct lelement* next=llm__next(head1);
      next=NULL;
      struct lelement* prev=llm__prev(head1);
      prev=NULL;
      lnk__add_head(dequeue->l,head1);
      //printf("2*********************");
      //return 0;
    }
    else{
      //head->array le pointeur first n'est pas tout en bas
      //=>application d'un push_front supplementaire SUR LE ARRAY.
      array__push_front(head->array,x);
      //printf("3*********************");
      //dequeue->l->head=head;(pas necessaire du tout!!!!!!!!!)
      //si le lecteur ignore l'using de l'outil logiciel developpemnt gdb
      //  on lui invite a decommenter les printf((s)) sans les \n pour savoir
	//cequi cloche at all ~--.
      return 0;
    }
  }
}
				     
      


    
    

    


