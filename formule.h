#ifndef FORMULE_H
#define FORMULE_H

#include "operateur.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

struct formule {
	struct operateur * operateur;
	struct formule ** arguments;
	// Pour la suppression:
	// puisque les formules ne forment pas un arbre (contrairement aux autres structures)
	// on retient le nombre d'objets pointants vers une formule
	// on supprime la formule dès il n'y en a plus
	// Attention : interdit la suppression « manuelle »
	int pointages;
	// Pour la copie parallèle d'une formule
	struct formule * copie;
};

struct formule * formule_variable(char * ecrit, char * latex);
struct formule * formule_creer(struct operateur * O, ...);
void formule_supprimer(struct formule * F);

struct formule * pointer(struct formule * F);

bool formule_egale(struct formule * F, struct formule * G);
void formule_afficher(struct formule * F);

#endif
