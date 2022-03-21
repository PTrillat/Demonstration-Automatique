#include "deduction.h"

struct deduction * deduction_creer(int n, struct formule * conc, ...) {
	struct deduction ** hypotheses = malloc(sizeof(struct deduction *) * n);
	va_list curseur;
	va_start(curseur, conc);
	for (int i=0; i<n; i++) hypotheses[i] = va_arg(curseur, struct deduction *);
	va_end(curseur);
	struct deduction * D = malloc(sizeof(struct deduction));
	D->n = n;
	D->hypotheses = hypotheses;
	D->conclusion = pointer(conc);
	return D;
}

void deduction_supprimer(struct deduction * D) {
	for (int i=0; i<D->n; i++) deduction_supprimer(D->hypotheses[i]);
	formule_supprimer(D->conclusion);
	free(D);
}

void deduction_supprimer_bavarde(struct deduction * D, int t) {
	for (int i=0; i<t; i++) printf(" ");
	printf("Suppression de la deduction:\n");
	for (int i=0; i<D->n; i++) deduction_supprimer_bavarde(D->hypotheses[i], t+1);
	formule_supprimer_bavarde(D->conclusion, t+1);
	free(D);
	printf("Fin de la supression de la deduction\n");
}

void deduction_afficher(struct deduction * D, int t) {
	for (int i=0; i<D->n; i++) deduction_afficher(D->hypotheses[i], t+1);
	for (int k=0; k<t; k++) printf("%s", "\t");
	//printf("----------------\n");
	for (int k=0; k<t; k++) printf("%s", "\t");
	formule_afficher(D->conclusion);
	printf("\n");
}
