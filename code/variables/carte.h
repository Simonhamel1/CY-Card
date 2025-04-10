#ifndef CARTE_H
#define CARTE_H

struct carte {
    int valeur;      // Valeur de la carte de -2 à 12
    int visible;     // 0: cachée, 1: visible
    int couleur;     // 1: rouge, 2: orange, 3: jaune, 4: vert
};
typedef struct carte * Carte;

struct jeu_de_cartes {
    Carte *cartes;   // Tableau dynamique de cartes
    int taille;      // Nombre total de cartes
    int capacite;    // Capacité actuelle du tableau
};
typedef struct jeu_de_cartes * JeuDeCartes;

JeuDeCartes *creer_jeu_de_cartes(int capacite_initiale);
void liberer_jeu_de_cartes(JeuDeCartes jeu);

Carte *initialiserCartes(int variante);
Carte creer_carte(int valeur, const char *ignore);
void afficher_carte(Carte carte);

#endif
