#ifndef JOUEUR_H
#define JOUEUR_H

#include "carte.h"

#define MAX_CARTES 5
#define MAX_DEFAUSSE 20

typedef struct {
    char nom[50];
    Carte* cartes;      // Main (jeu personnel), 5 cartes
    int nb_cartes;
    Carte* defausse;    // Tas de défausse du joueur
    int nb_defausse;
} Joueur;

Joueur creer_joueur(const char* nom);
void ajouter_carte(Joueur* joueur, Carte carte);
void afficher_cartes(Joueur joueur);
int calculer_score(Joueur joueur);

#endif
