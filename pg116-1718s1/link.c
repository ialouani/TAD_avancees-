#include <stdlib.h>
#include <assert.h>

#include "link.h"

struct link lnk__empty(void)
{
  struct link l = {NULL, NULL};
  return l;
}

struct lelement * lnk__first(struct link const * l)
{
  return l->head;
}

struct lelement * lnk__last(struct link const * l)
{
  return l->tail;
}

int llm__is_end_mark(struct lelement const * e)
{
  return (e == NULL);
}

struct lelement * llm__next(struct lelement const * e)
{
  return e->next;
}

struct lelement * llm__prev(struct lelement const * e)
{
  return e->prev;
}

void lnk__add_head(struct link * l, struct lelement * e)
{
  e->next = l->head;
  e->prev = NULL;

  if (e->next != NULL)
    e->next->prev = e;
  
  l->head = e;

  if (l->tail == NULL)
    l->tail = l->head;
}

struct lelement * lnk__remove_head(struct link * l)
{
  struct lelement * tmp = l->head;
  lnk__remove(l, tmp);
  return tmp;
}

void lnk__add_tail(struct link * l, struct lelement * e)
{
  if (l->tail == NULL) {
    lnk__add_head(l, e);
    return;
  }

  e->next = NULL;
  e->prev = l->tail;

  e->prev->next = e;

  l->tail = e;
}

struct lelement * lnk__remove_tail(struct link * l)
{
  struct lelement * tmp = l->tail;
  lnk__remove(l, tmp);
  return tmp;
}


void lnk__remove(struct link * l, struct lelement * e)
{
  if (e == NULL)
    return;

  if (e->prev != NULL)
    e->prev->next = e->next;
  if (e->next != NULL)
    e->next->prev = e->prev;

  if (l->head == e)
    l->head = e->next;
  if (l->tail == e)
    l->tail = e->prev;

  e->next = NULL;
  e->prev = NULL;
}
