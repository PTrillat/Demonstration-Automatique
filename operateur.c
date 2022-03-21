#include "operateur.h"

struct operateur * operateur_creer(int arite, char * ecrit, char * latex) {
	struct operateur * O = malloc(sizeof(struct operateur));
	O->arite = arite;
	O->ecrit = ecrit;
	O->latex = latex;
	return O;
}

void operateur_supprimer(struct operateur * O) {
	//free(O->ecrit);	//statique
	//free(O->latex);	//statique
	free(O);
}

void operateur_supprimer_bavarde(struct operateur * O, int t) {
	for (int i=0; i<t; i++) printf(" ");
	printf("Suppression de l'opérateur\n");
	//free(O->ecrit);	//statique
	//free(O->latex);	//statique
	free(O);
	for (int i=0; i<t; i++) printf(" ");
	printf("Fin de la supression de l'opérateur\n");
}
