#ifndef DEDUCTION_H
#define DEDUCTION_H

#include "formule.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

struct deduction {
	// Aucune déduction ne se fera avec plus de deux hypothèses
	// Statique car on ne supprimera pas une déduction au cours de l'execution du programme
	//struct deduction * hypotheses[2];
	int n; // nombre d'hypothèses
	struct deduction ** hypotheses;
	struct formule * conclusion;
};

struct deduction * deduction_creer(int n, struct formule * conc, ...);
void deduction_supprimer(struct deduction * D);
void deduction_supprimer_bavarde(struct deduction * D, int t);

void deduction_afficher(struct deduction * D, int t);

#endif
