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
	int pointages;
	// Nombre de pointages vers cette formule.
	// Si l'on veut avoir un autre pointeur vers une formule existante on écrira donc:
	//  struct formule * F = creer_variable("x", "\\mathfrak{X}"); // 0 pointeur vers la mémoire de F
	//  struct formule * G = pointer(G); // 1 pointeurs
	// De sorte que :
	//  formule_supprimer(F); // ne supprime pas la mémoire car G pointe encore dessus
	//  formule_supprimer(G); // supprime tout
	struct formule * injection; // Pour la copie parallèle d'une formule
};

struct formule * formule_variable(char * ecrit, char * latex);
struct formule * formule_creer(struct operateur * O, ...);
void formule_supprimer(struct formule * F);
void formule_supprimer_bavarde(struct formule * F, int t);

struct formule * pointer(struct formule * F);

bool formule_egale(struct formule * F, struct formule * G);
void formule_afficher(struct formule * F);

struct formule * formule_copier(struct formule * F);

#endif
