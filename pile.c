#include "pile.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct pile {
	char val;
	pile* next;
};

pile* init_pile(void){
	return NULL;
}

bool est_vide(pile* p) {
	return (NULL == p);
}

void push(pile** pp,char c) {
	pile* r = malloc(sizeof *r);
	r->val=c;
	r->next=*pp;
	*pp = r;
}

void pop(pile** pp) {
	if(!est_vide(*pp)){
		pile* tmp=(*pp)->next;
		free(*pp);
		*pp = tmp;
	}
}

void free_pile(pile **pp){
	while(!est_vide(*pp)){
		pop(pp);
	}
}

char get_head(pile *p){
	if(!est_vide(p)){
		return p->val;
	}
	else{
		printf("pile vide\n");
		return '\0';
	}
}

pile* get_next(pile *p){
	if(!est_vide(p)){
		return p->next;
	}
	else{
		printf("pile vide\n");
		return NULL;
	}
}

int pilelen(pile *p){
	int res = 0;

	while(!est_vide(p)){
		res = res+1;
		p = get_next(p);
	}

	return res;
}

void print_pile(pile *p){
	while(!est_vide(p)){
		printf("%c", p->val);
		p = get_next(p);
	}
	printf("\n");
}
