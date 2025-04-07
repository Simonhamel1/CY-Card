#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#include "joueur.h"
#include "carte.h"

static void shuffle(Carte* deck, int n) {
    for(int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        Carte temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

Jeu creer_jeu(int nb_joueurs) {
    Jeu jeu;
    jeu.nb_joueurs = nb_joueurs;
    jeu.joueurs = malloc(nb_joueurs * sizeof(Joueur));
    for (int i = 0; i < nb_joueurs; i++) {
        char nom[50];
        sprintf(nom, "Joueur %d", i + 1);
        jeu.joueurs[i] = creer_joueur(nom);
    }
    jeu.pioche = NULL;
    jeu.taille_pioche = 0;
    jeu.tour = 0;
    srand(time(NULL));
    return jeu;
}

void initialiser_pioche(Jeu* jeu) {
    // Création du deck complet selon la répartition
    int total = 5 + 10 + 15 + (12 * 10); // 150 cartes
    Carte* deck = malloc(total * sizeof(Carte));
    int index = 0;
    // Valeur -2: 5 cartes, couleur "Noir"
    for (int i = 0; i < 5; i++) {
        deck[index++] = creer_carte(-2, "Noir");
    }
    // Valeur -1: 10 cartes, couleur "Rouge"
    for (int i = 0; i < 10; i++) {
        deck[index++] = creer_carte(-1, "Rouge");
    }
    // Valeur 0: 15 cartes, couleur "Vert"
    for (int i = 0; i < 15; i++) {
        deck[index++] = creer_carte(0, "Vert");
    }
    // Valeurs 1 à 12: 10 cartes chacune, couleur "Bleu"
    for (int v = 1; v <= 12; v++) {
        for (int i = 0; i < 10; i++) {
            deck[index++] = creer_carte(v, "Bleu");
        }
    }
    // Mélange du deck
    shuffle(deck, total);
    
    // Distribution initiale : 5 cartes par joueur
    for (int i = 0; i < jeu->nb_joueurs; i++) {
        for (int j = 0; j < MAX_CARTES; j++) {
            ajouter_carte(&jeu->joueurs[i], deck[0]);
            // Supprimer la première carte du deck en décalant les éléments
            for (int k = 0; k < total - 1; k++) {
                deck[k] = deck[k+1];
            }
            total--;
        }
    }
    // Le reste du deck devient la pioche centrale
    jeu->pioche = deck;
    jeu->taille_pioche = total;
}

void jouer_tour(Jeu* jeu) {
    Joueur* joueur = &jeu->joueurs[jeu->tour];
    printf("\n--- Tour de %s ---\n", joueur->nom);
    afficher_cartes(*joueur);
    
    printf("Choisissez la source de tirage:\n");
    printf("1: Pioche\n2: Défausse\n");
    int choix;
    scanf("%d", &choix);
    Carte drawn;
    if (choix == 1) {
        if (jeu->taille_pioche <= 0) {
            printf("La pioche est vide!\n");
            return;
        }
        drawn = jeu->pioche[0];
        // Retrait de la carte de la pioche
        for (int i = 0; i < jeu->taille_pioche - 1; i++) {
            jeu->pioche[i] = jeu->pioche[i+1];
        }
        jeu->taille_pioche--;
    } else if (choix == 2) {
        int jnum;
        printf("Entrez le numéro du joueur dont vous voulez prendre la défausse (1-%d): ", jeu->nb_joueurs);
        scanf("%d", &jnum);
        jnum--;
        if(jnum < 0 || jnum >= jeu->nb_joueurs) {
            printf("Numéro de joueur invalide.\n");
            return;
        }
        if(jeu->joueurs[jnum].nb_defausse <= 0) {
            printf("La défausse de ce joueur est vide.\n");
            return;
        }
        // Prendre la dernière carte de la défausse
        drawn = jeu->joueurs[jnum].defausse[jeu->joueurs[jnum].nb_defausse - 1];
        jeu->joueurs[jnum].nb_defausse--;
    } else {
        printf("Choix invalide.\n");
        return;
    }
    
    printf("Carte tirée: ");
    afficher_carte(drawn);
    
    printf("Choisissez l'indice de la carte de votre main à échanger (1-%d): ", joueur->nb_cartes);
    int indice;
    scanf("%d", &indice);
    if (indice < 1 || indice > joueur->nb_cartes) {
        printf("Indice invalide.\n");
        return;
    }
    indice--;
    // La carte actuellement en main va à la défausse (elle devient visible)
    Carte old = joueur->cartes[indice];
    old.visible = 1;
    joueur->defausse[joueur->nb_defausse++] = old;
    // La nouvelle carte prend place dans la main, en restant cachée
    drawn.visible = 0;
    joueur->cartes[indice] = drawn;
    
    // Vérification : si toutes les cartes sont révélées, la partie se termine
    int all_visible = 1;
    for (int i = 0; i < joueur->nb_cartes; i++) {
        if (joueur->cartes[i].visible == 0) {
            all_visible = 0;
            break;
        }
    }
    if (all_visible) {
        printf("Toutes vos cartes sont révélées ! Fin de la partie.\n");
        fin_de_partie(*jeu);
        exit(0);
    }
    
    // Passage au tour suivant
    jeu->tour = (jeu->tour + 1) % jeu->nb_joueurs;
}

void fin_de_partie(Jeu jeu) {
    printf("\n--- Fin de Partie ---\n");
    for (int i = 0; i < jeu.nb_joueurs; i++) {
        // Révélation de toutes les cartes
        for (int j = 0; j < jeu.joueurs[i].nb_cartes; j++) {
            jeu.joueurs[i].cartes[j].visible = 1;
        }
        printf("%s, score: %d points\n", jeu.joueurs[i].nom, calculer_score(jeu.joueurs[i]));
    }
}
