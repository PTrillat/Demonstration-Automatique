#ifndef FORMULE_H
#define FORMULE_H

#include "operateur.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

# define formule struct FORMULE // pas beau mais ça marche

formule {
	operateur * operateur;
	formule ** arguments;
	// Pour la suppression:
	// puisque les formules ne forment pas un arbre (contrairement aux autres structures)
	// on retient le nombre d'objets pointants vers une formule
	// on supprime la formule dès il n'y en a plus
	// Attention : interdit la suppression « manuelle »
	int pointages;
	// Pour la copie parallèle d'une formule
	formule * copie;
};

formule * formule_a_partir(operateur * O, ...);
formule * formule_creer(operateur * O, formule ** args);
void formule_supprimer(formule * F);

#endif
