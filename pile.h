#include <stdbool.h>

typedef struct pile pile;

pile* pile_init(void);

bool est_vide(pile*);

void push(pile**, char);

void pop(pile**);

char get_head(pile *p);

pile* get_next(pile *p);

void free_pile(pile **pp);
