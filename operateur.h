#ifndef OPERATEUR_H
#define OPERATEUR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int arite;	// nombre de formules sur lesquelles agit l'opérateur
	char * ecrit;
	char * latex;
} operateur;

operateur * operateur_creer(int arite, char * ecrit, char * latex);
void operateur_supprimer(operateur * O);

#endif
