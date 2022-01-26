#include "formule.h"

formule * formule_a_partir(operateur * O, ...) {
	formule ** args = malloc(sizeof(formule*) * O->arite);
	va_list curseur;
	va_start(curseur, O);
	for (int i=0; i<O->arite; i++) {
		args[i] = va_arg(curseur, formule *);
		args[i]->pointages++;
	}
	va_end(curseur);
	return formule_creer(O, args);
}

formule * formule_creer(operateur * O, formule ** args) {
	formule * F = malloc(sizeof(formule));
	F->operateur = O;
	F->arguments = args;
	F->pointages = 0;
	F->copie = NULL;
	return F;
}

void formule_supprimer(formule * F) {
	// TODO printf("Suppression de la formule: %s\n", formule_ecrit(F));
	printf("Suppression de la formule: %s\n", "indisponible");
	F->pointages--;
	if (F->pointages < 0) {
		printf("\tDestruction:\n");
		for (int i=0; i<F->operateur->arite; i++) formule_supprimer(F->arguments[i]);
		free(F->arguments);
		//free(F->copie) // doit toujours être NULL en dehors de la duplication
		free(F);
	}
	printf("Fin de la supression\n");
}
