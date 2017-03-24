#include "pile.h"
#include <stdlib.h>
#include <stdbool.h>

struct pile {
	char val;
	pile* next;
};

pile* init_pile(void){
	return 0;
}

bool est_vide(pile* p) {
	return (0 == p);
}

void push(pile** pp,char c) {
	pile* r = malloc(sizeof *r);
	r->val=c;
	r->next=*pp;
	*pp = r;
}

void pop(pile** pp) {
	pile* tmp=(*pp)->next;
	free(*pp);
	*pp = tmp;
}

void free_pile(pile **pp){
	while(!est_vide(*pp)){
		pop(pp);
	}
}

char get_head(pile *p){
	return p->val;
}

pile* get_next(pile *p){
	return p->next;
}
