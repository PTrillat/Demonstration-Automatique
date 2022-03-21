#ifndef OPERATEUR_H
#define OPERATEUR_H

#include <stdio.h>
#include <stdlib.h>

struct operateur {
	//char type;	// type des formules sur lesquelles agit l'opérateur
	int arite;	// nombre de formules sur lesquelles agit l'opérateur
	char * ecrit;
	char * latex;
};

struct operateur * operateur_creer(int arite, char * ecrit, char * latex);
void operateur_supprimer(struct operateur * O);
void operateur_supprimer_bavarde(struct operateur * O, int t);

#endif
