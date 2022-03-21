#include "regle.h"

struct formule * fonction_regle(struct formule * axiome, int n, ...) {
	struct formule * variable;
	struct formule * nouvelle;
	va_list curseur;
	va_start(curseur, n);
	for (int i=0; i<n; i++) {
		variable = va_arg(curseur, struct formule *);
		nouvelle = va_arg(curseur, struct formule *);
		variable->injection = nouvelle;
	}
	va_end(curseur);
	struct formule * F = formule_copier(axiome);
	va_start(curseur, n);
	for (int i=0; i<n; i++) {
		variable = va_arg(curseur, struct formule *);
		nouvelle = va_arg(curseur, struct formule *);
		variable->injection = NULL;
	}
	va_end(curseur);
	return F;
}
