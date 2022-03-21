#include "operateur.h"
#include "formule.h"
#include "deduction.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	struct operateur * et = operateur_creer(2, "&", "\\land");
	struct operateur * non = operateur_creer(1, "~", "\\neg");
	
	struct formule * x = pointer(formule_variable("x", "x"));
	struct formule * y = pointer(formule_variable("y", "y"));
	struct formule * nx = pointer(formule_creer(non, x));
	struct formule * ny = pointer(formule_creer(non, y));
	
	struct formule * nxey1 = pointer(formule_creer(et, nx, y));
	struct formule * xey2 = pointer(formule_creer(et, x, y));
	
	printf("%d\n", formule_egale(nxey1, xey2));
	
	formule_supprimer(nxey1);
	formule_supprimer(xey2);
	
	struct deduction * d = deduction_creer(2,
				formule_creer(et, nx, ny),
				deduction_creer(0,nx),
				deduction_creer(0,ny)
				);
	
	deduction_ecrit_afficher(d, 0);
	
	deduction_supprimer(d);
	formule_supprimer(nx);
	formule_supprimer(ny);
	formule_supprimer(y);
	formule_supprimer(x);
	operateur_supprimer(et);		
	return 0;
}
