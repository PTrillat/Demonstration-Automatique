#include "operateur.h"

operateur * operateur_creer(int arite, char * ecrit, char * latex) {
	operateur * O = malloc(sizeof(operateur));
	O->arite = arite;
	O->ecrit = ecrit;
	O->latex = latex;
	return O;
}

void operateur_supprimer(operateur * O) {
	printf("Destruction de l'opérateur: %s\n", O->ecrit);
	//free(O->ecrit);	//statique
	//free(O->latex);	//statique
	free(O);
	printf("Fin de la supression\n");
}
