#ifndef CARTE_H
#define CARTE_H

typedef struct {
    int valeur;           // Valeur de la carte
    char couleur[20];     // Couleur de la carte
    int visible;          // 0: cachée, 1: visible
} Carte;

Carte creer_carte(int valeur, const char* couleur);
void afficher_carte(Carte carte);

#endif
