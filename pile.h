#include <stdbool.h>

typedef struct pile pile;

pile* init_pile(void);

bool est_vide(pile* p);

void push(pile** pp, char c);

void pop(pile** pp);

char get_head(pile *p);

pile* get_next(pile *p);

int pilelen(pile *p);

void print_pile(pile *p);

void free_pile(pile **pp);

pile * reverse(pile *p);
