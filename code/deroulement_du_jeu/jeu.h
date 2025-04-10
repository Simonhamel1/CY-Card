#ifndef JEU_H
#define JEU_H

#include "joueur.h"
#include "carte.h"

typedef struct {
    Joueur* joueurs;
    int nb_joueurs;
    Carte* pioche;       // Deck central restant
    int taille_pioche;
    int tour;            // Indice du joueur courant
} Jeu;

Jeu creer_jeu(int nb_joueurs);
void initialiser_pioche(Jeu* jeu);
void jouer_tour(Jeu* jeu);
void fin_de_partie(Jeu jeu);

#endif
