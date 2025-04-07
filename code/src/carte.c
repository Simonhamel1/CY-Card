#include <stdio.h>
#include <string.h>
#include "carte.h"

Carte creer_carte(int valeur, const char* couleur) {
    Carte carte;
    carte.valeur = valeur;
    strcpy(carte.couleur, couleur);
    carte.visible = 0;
    return carte;
}

void afficher_carte(Carte carte) {
    if(carte.visible) {
        printf("┌───────┐\n");
        printf("│ %3d   │\n", carte.valeur);
        printf("│%-7s│\n", carte.couleur);
        printf("└───────┘\n");
    } else {
        printf("┌───────┐\n");
        printf("│ ***** │\n");
        printf("│ ***** │\n");
        printf("└───────┘\n");
    }
}
