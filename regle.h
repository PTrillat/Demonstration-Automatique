#ifndef REGLE_H
#define REGLE_H

#include "formule.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

struct formule * fonction_regle(struct formule * axiome, int n, ...);

#endif
