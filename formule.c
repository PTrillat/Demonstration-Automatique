#include "formule.h"

struct formule * formule_variable(char * ecrit, char * latex) {
	struct formule * F = malloc(sizeof(struct formule));
	F->operateur = operateur_creer(0, ecrit, latex);
	F->arguments = NULL;
	F->pointages = 0; // un truc derrière qui récupère cette formule
	F->injection = NULL;
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
	F->pointages = 0; // un truc derrière qui récupère cette formule
	F->injection = NULL;
	return F;
}

void formule_supprimer(struct formule * F) {
	F->pointages--;
	if (F->pointages<=0) {
		if (F->arguments==NULL) {
			operateur_supprimer(F->operateur);
		} else {
			for (int i=0; i<F->operateur->arite; i++) formule_supprimer(F->arguments[i]);
			free(F->arguments);
		}
		free(F);
	}
}

void formule_supprimer_bavarde(struct formule * F, int t) {
	for (int i=0; i<t; i++) printf(" ");
	printf("Suppression de la formule: ");
	formule_afficher(F); printf("\n");
	//
	F->pointages--;
	if (F->pointages < 0) {
		printf("!!!!!!\n");
		F->pointages = 0;
	}
	//
	if (F->pointages==0) {
		if (F->arguments==NULL) {
			operateur_supprimer_bavarde(F->operateur, t+1);
		} else {
			for (int i=0; i<F->operateur->arite; i++) formule_supprimer_bavarde(F->arguments[i], t+1);
			free(F->arguments);
		}
		free(F);
	}
	for (int i=0; i<t; i++) printf(" ");
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
			formule_afficher_parenthese(F->arguments[0]);
			break;
		case 2:
			formule_afficher_parenthese(F->arguments[0]);
			printf("%s", F->operateur->ecrit);
			formule_afficher_parenthese(F->arguments[1]);
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
	printf("%d", F->pointages);
}

struct formule * formule_copier(struct formule * F) {
	struct formule * copie;
	if (F->arguments!=NULL) {
		struct formule ** arguments = malloc(sizeof(struct formule*) * F->operateur->arite);
		for (int i=0; i<F->operateur->arite; i++) arguments[i] = pointer(formule_copier(F->arguments[i]));
		copie = malloc(sizeof(struct formule));
		copie->operateur = F->operateur;
		copie->arguments = arguments;
		copie->pointages = 0;
		copie->injection = NULL;
	} else if (F->injection!=NULL) {
		copie = formule_copier(F->injection);
	} else {
		copie = F;
	}
	formule_afficher(F); printf(" --> "); formule_afficher(copie); printf("\n");
	return copie;
}
