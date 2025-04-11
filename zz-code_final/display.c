#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "display.h"
#include "game.h"

// Fonction pour obtenir la couleur associée à une valeur de carte
const char* obtenir_couleur(int valeur) {
    if (valeur == EMPTY_CARD) return BLANC; // Cartes non retournées en blanc
    switch (valeur) {
        case -5: return ROUGE;
        case -4: return B_ROUGE;
        case -3: return VERT;
        case -2: return B_VERT;
        case -1: return JAUNE;
        case  0: return B_JAUNE;
        case  1: return BLEU;
        case  2: return B_BLEU;
        case  3: return MAGENTA;
        case  4: return B_MAGENTA;
        case  5: return CYAN;
        case  6: return B_CYAN;
        case  7: return ROUGE;
        case  8: return B_ROUGE;
        case  9: return VERT;
        case 10: return B_VERT;
        case 11: return BLEU;
        case 12: return B_BLEU;
        case 13: return MAGENTA;
        case 14: return B_MAGENTA;
        case 15: return CYAN;
        default: return BLANC; // Valeur par défaut
    }
}

// Fonction pour afficher une ligne de cartes
void afficher_ligne_cartes(int joueurs[][MAX_CARDS_PER_PLAYER], int debut, int fin, int indice_carte_debut, int indice_carte_fin) {
    // Première ligne des cartes (bordure supérieure)
    for (int j = debut; j <= fin; j++) {
        for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
            const char* couleur = obtenir_couleur(joueurs[j][i]);
            printf("%s┌──────┐%s ", couleur, RESET);
        }
        printf("   ");  // Espace entre les joueurs
    }
    printf("\n");

    // Deuxième ligne (CARD)
    for (int j = debut; j <= fin; j++) {
        for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
            const char* couleur = obtenir_couleur(joueurs[j][i]);
            printf("%s│ CARD │%s ", couleur, RESET);
        }
        printf("   ");
    }
    printf("\n");

    // Troisième ligne (numéro de la carte)
    for (int j = debut; j <= fin; j++) {
        for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
            const char* couleur = obtenir_couleur(joueurs[j][i]);
            if (joueurs[j][i] == EMPTY_CARD) {
                printf("%s│~~~~~~│%s ", couleur, RESET);
            } else if (joueurs[j][i] < 0 || joueurs[j][i] > 9) {
                printf("%s│  %d  │%s ", couleur, joueurs[j][i], RESET);
            } else {
                printf("%s│   %d  │%s ", couleur, joueurs[j][i], RESET);
            }
        }
        printf("   ");
    }
    printf("\n");

    // Quatrième ligne (YARD)
    for (int j = debut; j <= fin; j++) {
        for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
            const char* couleur = obtenir_couleur(joueurs[j][i]);
            printf("%s│ YARD │%s ", couleur, RESET);
        }
        printf("   ");
    }
    printf("\n");

    // Cinquième ligne (bordure inférieure)
    for (int j = debut; j <= fin; j++) {
        for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
            const char* couleur = obtenir_couleur(joueurs[j][i]);
            printf("%s└──────┘%s ", couleur, RESET);
        }
        printf("   ");
    }
    printf("\n");
}

// Fonction pour afficher les défausses
void afficher_defausses(int defausses[], int debut, int fin) {
    // Bordure supérieure
    for (int j = debut; j <= fin; j++) {
        const char* couleur = obtenir_couleur(defausses[j]);
        printf("         %s┌──────┐%s             ", couleur, RESET);
    }
    printf("\n");

    // Ligne DEFAUSSE
    for (int j = debut; j <= fin; j++) {
        const char* couleur = obtenir_couleur(defausses[j]);
        printf("         %s│DEFAU.│%s             ", couleur, RESET);
    }
    printf("\n");

    // Valeur de la carte
    for (int j = debut; j <= fin; j++) {
        const char* couleur = obtenir_couleur(defausses[j]);
        if (defausses[j] == EMPTY_CARD) {
            printf("         %s│~~~~~~│%s             ", couleur, RESET);
        } else if (defausses[j] < 0 || defausses[j] > 9) {
            printf("         %s│  %d  │%s             ", couleur, defausses[j], RESET);
        } else {
            printf("         %s│   %d  │%s             ", couleur, defausses[j], RESET);
        }
    }
    printf("\n");

    // Ligne JOUEUR
    for (int j = debut; j <= fin; j++) {
        const char* couleur = obtenir_couleur(defausses[j]);
        printf("         %s│      │%s             ", couleur, RESET);
    }
    printf("\n");

    // Bordure inférieure
    for (int j = debut; j <= fin; j++) {
        const char* couleur = obtenir_couleur(defausses[j]);
        printf("         %s└──────┘%s             ", couleur, RESET);
    }
    printf("\n");
}

// Autres fonctions (afficher_numeros_joueurs, afficher_pioche, afficher_jeu, afficher_bienvenue, afficher_instructions)
// restent inchangées pour des raisons de concision.
