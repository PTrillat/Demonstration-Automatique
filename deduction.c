#include "deduction.h"

struct deduction * deduction_creer(int n, struct formule * conc, ...) {
	struct deduction * D = malloc(sizeof(struct deduction));
	D->n = n;
	D->conclusion = pointer(conc);
	D->hypotheses = malloc(sizeof(struct deduction *) * n);
	va_list curseur;
	va_start(curseur, conc);
	for (int i=0; i<n; i++) D->hypotheses[i] = va_arg(curseur, struct deduction *);
	va_end(curseur);
	return D;
}

void deduction_supprimer(struct deduction * D) {
	printf("Suppression de la deduction:\n");
	formule_supprimer(D->conclusion);
	for (int i=0; i<D->n; i++) deduction_supprimer(D->hypotheses[i]);
	printf("Fin de la supression de la deduction\n");
}

void deduction_afficher(struct deduction * D, int t) {
	for (int i=0; i<D->n; i++) deduction_ecrit_afficher(D->hypotheses[i], t+1);
	for (int k=0; k<t; k++) printf("%s", "\t");
	//printf("----------------\n");
	for (int k=0; k<t; k++) printf("%s", "\t");
	formule_ecrit_afficher(D->conclusion);
	printf("\n");	
}
