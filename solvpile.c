#include "pile.h"
#include "solvpile.h"

struct solvpile {
	pile *sol;
	solvpile *next;
	};

solvpile* init_solvpile(void){
		return NULL;
}
bool solvest_vide(solvpile* p) {
	return (0 == p);
}

void solvpush(solvpile** pp, pile* v) {

	if(!est_vide(v)){
		solvpile* r = malloc(sizeof *r);
		r->sol=v;
		r->next=*pp;
		*pp = r;
	}
	else{
		printf("v est vide");
	}
}

pile* minpile(solvpile* p){
	pile *min=p->sol;
	int l=pilelen(min);
	while(p!=NULL){
		if(l>pilelen(p->sol)){
			l=pilelen(p->sol);
			min=p->sol;
		}
		p=p->next;
	}
return min;
}


void solvpop(solvpile** pp) {
	solvpile* tmp=(*pp)->next;
	free(*pp);
	*pp = tmp;
}

void print_solvpile(solvpile *p){
	if(p==NULL) printf("Pile vide");
	while(p!=NULL){
		print_pile(p->sol);
		printf("\n");
		p=p->next;
	}
}

void free_solvpile(solvpile **pp){
	while(!solvest_vide(*pp)){
		solvpop(pp);
	}
}


pile * solvget_head(solvpile *pp){
	if(!solvest_vide(pp)){
		return pp->sol;
	}
	else{
		return NULL;
	}
}

solvpile * solvget_next(solvpile *pp){
	if(!solvest_vide(pp)){
	return pp->next;
	}
	else{
		return NULL;
	}
}
