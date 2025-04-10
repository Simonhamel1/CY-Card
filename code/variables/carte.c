#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "carte.h"

#define VALUE_USER 1

// On suppose que la structure carte est étendue dans "carte.h" pour inclure un champ "couleur"
// struct carte {
//     int valeur;
//     int visible;
//     int couleur; // 1: rouge (pour -2), 2: orange (pour -1), 3: jaune (pour 0), 4: vert (pour valeurs positives)
// };

static int get_couleur(int valeur) {
    if (valeur == -2)
        return 1;
    else if (valeur == -1)
        return 2;
    else if (valeur == 0)
        return 3;
    else
        return 4;
}

// Création d'un jeu de cartes avec une capacité prédéfinie
JeuDeCartes creer_jeu_de_cartes(int capacite_initiale) {
    JeuDeCartes jeu = malloc(sizeof(struct jeu_de_cartes));
    if (!jeu) {
        fprintf(stderr, "Erreur d'allocation mémoire pour le jeu de cartes\n");
        return NULL;
    }
    jeu->cartes = malloc(sizeof(Carte) * capacite_initiale);
    if (!jeu->cartes) {
        fprintf(stderr, "Erreur d'allocation mémoire pour les cartes\n");
        free(jeu);
        return NULL;
    }
    jeu->taille = 0;
    jeu->capacite = capacite_initiale;
    return jeu;
}

void liberer_jeu_de_cartes(JeuDeCartes jeu) {
    if (jeu) {
        if (jeu->cartes) {
            for (int i = 0; i < jeu->taille; i++) {
                free(jeu->cartes[i]);
            }
            free(jeu->cartes);
        }
        free(jeu);
    }
}

// Fonction pour initialiser les cartes.
// Si la variante est VALUE_USER, la plage de valeurs est demandée à l'utilisateur.
// Par défaut, les quantités sont : 5 cartes pour -2, 10 cartes pour -1, 15 cartes pour 0,
// et 10 cartes pour chaque valeur positive (ou toute autre valeur).
Carte *initialiserCartes(int variante) {
    int total = 0;
    int min_val, max_val;
    if (variante == VALUE_USER) {
        printf("Entrez la valeur minimale : ");
        scanf("%d", &min_val);
        printf("Entrez la valeur maximale : ");
        scanf("%d", &max_val);
    } else {
        min_val = -2;
        max_val = 12;
    }
    for (int v = min_val; v <= max_val; v++) {
        if (v == -2)
            total += 5;
        else if (v == -1)
            total += 10;
        else if (v == 0)
            total += 15;
        else
            total += 10;
    }

    Carte *cartes = malloc(sizeof(Carte) * total);
    if (!cartes) {
        fprintf(stderr, "Erreur d'allocation mémoire pour les cartes\n");
        return NULL;
    }
    int index = 0;
    for (int v = min_val; v <= max_val; v++) {
        int quantite;
        if (v == -2)
            quantite = 5;
        else if (v == -1)
            quantite = 10;
        else if (v == 0)
            quantite = 15;
        else
            quantite = 10;
        for (int i = 0; i < quantite; i++) {
            Carte carte = malloc(sizeof(struct carte));
            if (!carte) {
                fprintf(stderr, "Erreur d'allocation mémoire pour une carte\n");
                for (int k = 0; k < index; k++) {
                    free(cartes[k]);
                }
                free(cartes);
                return NULL;
            }
            carte->valeur = v;
            carte->visible = 0;
            carte->couleur = get_couleur(v);
            cartes[index++] = carte;
        }
    }
    return cartes;
}

// Fonction pour créer une carte : la couleur est déterminée par la valeur
Carte creer_carte(int valeur, const char *ignore) {
    Carte carte = malloc(sizeof(struct carte));
    if (!carte) {
        fprintf(stderr, "Erreur d'allocation mémoire pour une carte\n");
        return NULL;
    }
    carte->valeur = valeur;
    carte->visible = 0;
    carte->couleur = get_couleur(valeur);
    return carte;
}

// Affichage d'une carte avec couleur ANSI adaptée au terminal et en affichant juste des chiffres.
// Si la carte est visible, on affiche sa valeur colorée, sinon "XX".
void afficher_carte(Carte carte) {
    if (carte->visible) {
        char *ansi;
        switch (carte->couleur) {
            case 1: ansi = "\033[31m"; break; // rouge
            case 2: ansi = "\033[33m"; break; // orange (approximé)
            case 3: ansi = "\033[93m"; break; // jaune clair
            case 4: ansi = "\033[32m"; break; // vert
            default: ansi = "\033[0m"; break;
        }
        printf("┌───────┐\n");
        printf("│ %s%3d\033[0m │\n", ansi, carte->valeur);
        printf("└───────┘\n");
    } else {
        printf("┌───────┐\n");
        printf("│  XX   │\n");
        printf("└───────┘\n");
    }
}
