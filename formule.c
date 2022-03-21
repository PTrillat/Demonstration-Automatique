#include "formule.h"

struct formule * formule_variable(char * ecrit, char * latex) {
	struct formule * F = malloc(sizeof(struct formule));
	F->operateur = operateur_creer(0, ecrit, latex);
	F->arguments = NULL;
	F->pointages = 0;
	F->copie = NULL;
	return F;
}

struct formule * formule_creer(struct operateur * O, ...) {
	struct formule ** arguments = malloc(sizeof(struct formule*) * O->arite);
	va_list curseur;
	va_start(curseur, O);
	for (int i=0; i<O->arite; i++) arguments[i] = pointer(va_arg(curseur, struct formule *));
	va_end(curseur);
	struct formule * F = malloc(sizeof(struct formule));
	F->operateur = O;
	F->arguments = arguments;
	F->pointages = 0;
	F->copie = NULL;
	return F;
}

void formule_supprimer(struct formule * F) {
	printf("Suppression de la formule: "); formule_ecrit_afficher(F); printf("\n");
	F->pointages--;
	if (F->pointages <= 0) {
		if (F->pointages < 0) printf("!!!!!!\n");
		if (F->arguments==NULL) {
			operateur_supprimer(F->operateur);
			free(F);
		} else {
			for (int i=0; i<F->operateur->arite; i++) formule_supprimer(F->arguments[i]);
			free(F->arguments);
			free(F);
		}
	}
	printf("Fin de la supression de la formule\n");
}

struct formule * pointer(struct formule * F) {
	F->pointages++;
	return F;
}

bool formule_egale(struct formule * F, struct formule * G) {
	if (F->operateur != G->operateur) return false;
	for (int i=0; i<F->operateur->arite; i++) {
		if (!formule_egale(F->arguments[i], G->arguments[i])) return false;
	}
	return true;
}

void formule_afficher_parenthese(struct formule * F) {
	if (F->operateur->arite <= 1) {
		formule_afficher(F);
	} else {
		printf("(");
		formule_afficher(F);
		printf(")");
	}
}

void formule_afficher(struct formule * F) {
	switch (F->operateur->arite) {
		case 0:
			printf("%s", F->operateur->ecrit);
			break;
		case 1:
			printf("%s", F->operateur->ecrit);
			formule_ecrit_afficher_parenthese(F->arguments[0]);
			break;
		case 2:
			formule_ecrit_afficher_parenthese(F->arguments[0]);
			printf("%s", F->operateur->ecrit);
			formule_ecrit_afficher_parenthese(F->arguments[1]);
			break;
		default:
			printf("%s(", F->operateur->ecrit);
			for (int i=0; i<F->operateur->arite-1; i++) {
				formule_afficher(F->arguments[i]);
				printf(", ");
			}
			formule_afficher(F->arguments[F->operateur->arite-1]);
			printf(")");
			break;
	}
}
