#include "operateur.h"
#include "formule.h"
#include "deduction.h"
#include "regle.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	struct operateur * egale = operateur_creer(2, "=", "=");
	struct operateur * plus = operateur_creer(2, "+", "+");
	
	struct formule * x = formule_variable("x", "x");
	struct formule * y = formule_variable("y", "y");
	struct formule * xpyeypx = formule_creer(egale, formule_creer(plus, x, y), formule_creer(plus, y, x));
	formule_afficher(xpyeypx); printf("\n");
	
	struct formule * a = formule_variable("a", "a");
	struct formule * b = formule_variable("b", "b");
	struct formule * truc = fonction_regle(xpyeypx, 2, x, a, y, b);
	formule_afficher(truc); printf("\n");
	
	formule_supprimer_bavarde(truc, 0);
	formule_supprimer_bavarde(xpyeypx, 0);
	
	return 0;
}

/*int main() {
	struct operateur * et = operateur_creer(2, "&", "\\land");
	struct operateur * non = operateur_creer(1, "~", "\\neg");
	
	struct formule * x = pointer(formule_variable("x", "x"));
	struct formule * y = pointer(formule_variable("y", "y"));
	struct formule * nx = pointer(formule_creer(non, x));
	struct formule * ny = pointer(formule_creer(non, y));
	
	struct formule * nxey1 = pointer(formule_creer(et, nx, y));
	struct formule * xey2 = pointer(formule_creer(et, x, y));
	
	printf("%d\n", formule_egale(nxey1, xey2));
	
	formule_supprimer_bavarde(nxey1);
	formule_supprimer_bavarde(xey2);
	
	struct deduction * d = deduction_creer(2,
				formule_creer(et, nx, ny),
				deduction_creer(0,nx),
				deduction_creer(0,ny)
				);
	
	deduction_ecrit_afficher(d, 0);
	
	deduction_supprimer_bavarde(d);
	formule_supprimer_bavarde(nx);
	formule_supprimer_bavarde(ny);
	formule_supprimer_bavarde(y);
	formule_supprimer_bavarde(x);
	operateur_supprimer_bavarde(et);
	return 0;
}*/
