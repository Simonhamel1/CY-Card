#include "a.h"

int donner_nombre_aleatoire(int min, int max) {
    return rand() % (max - min + 1) + min;
}