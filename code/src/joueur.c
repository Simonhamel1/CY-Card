#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "joueur.h"
#include "carte.h"

Joueur creer_joueur(const char* nom) {
    Joueur joueur;
    strcpy(joueur.nom, nom);
    joueur.cartes = malloc(MAX_CARTES * sizeof(Carte));
    joueur.nb_cartes = 0;
    joueur.defausse = malloc(MAX_DEFAUSSE * sizeof(Carte));
    joueur.nb_defausse = 0;
    return joueur;
}

void ajouter_carte(Joueur* joueur, Carte carte) {
    if(joueur->nb_cartes < MAX_CARTES) {
        joueur->cartes[joueur->nb_cartes++] = carte;
    }
}

// Affichage des cartes côte à côte avec rendu en ASCII art
void afficher_cartes(Joueur joueur) {
    printf("%s, vos cartes:\n", joueur.nom);
    for (int line = 0; line < 4; line++) {
        for (int i = 0; i < joueur.nb_cartes; i++) {
            char buffer[50];
            if(joueur.cartes[i].visible) {
                switch(line) {
                    case 0:
                        sprintf(buffer, "┌───────┐ ");
                        break;
                    case 1:
                        sprintf(buffer, "│ %3d   │ ", joueur.cartes[i].valeur);
                        break;
                    case 2:
                        sprintf(buffer, "│%-7s│ ", joueur.cartes[i].couleur);
                        break;
                    case 3:
                        sprintf(buffer, "└───────┘ ");
                        break;
                }
            } else {
                switch(line) {
                    case 0:
                        sprintf(buffer, "┌───────┐ ");
                        break;
                    case 1:
                        sprintf(buffer, "│ ***** │ ");
                        break;
                    case 2:
                        sprintf(buffer, "│ ***** │ ");
                        break;
                    case 3:
                        sprintf(buffer, "└───────┘ ");
                        break;
                }
            }
            printf("%s", buffer);
        }
        printf("\n");
    }
}

int calculer_score(Joueur joueur) {
    int score = 0;
    for (int i = 0; i < joueur.nb_cartes; i++) {
        score += joueur.cartes[i].valeur;
    }
    return score;
}
