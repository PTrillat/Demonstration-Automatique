#include "operateur.h"
#include "formule.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	operateur * et = operateur_creer(0, "&", "\\land");
	formule * f = formule_a_partir(et);
	formule_supprimer(f);
	operateur_supprimer(et);		
	return 0;
}
