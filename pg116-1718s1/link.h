#ifndef _LINK_H_
#define _LINK_H_
#include"ex1.h"

struct array;

struct link {
  struct lelement * head;
  struct lelement * tail;
};

struct lelement {
  struct array * array;
  struct lelement * next;
  struct lelement * prev;
};

// link
struct link lnk__empty(void); 

void lnk__add_head(struct link *, struct lelement *);
struct lelement * lnk__remove_head(struct link *);

void lnk__add_tail(struct link *, struct lelement *);
struct lelement * lnk__remove_tail(struct link *);

void lnk__remove(struct link *, struct lelement *);

struct lelement * lnk__first(struct link const *);
struct lelement * lnk__last(struct link const *);

// lelement
int llm__is_end_mark(struct lelement const *);
struct lelement * llm__next(struct lelement const *);
struct lelement * llm__prev(struct lelement const *);

#endif /* _LINK_H_ */
