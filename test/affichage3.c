#include <stdio.h>
#include <stdlib.h>

// Fonction pour afficher une ligne de cartes pour plusieurs joueurs
void afficher_ligne_cartes(int joueurs[][6], int debut, int fin, int indice_carte_debut, int indice_carte_fin) {
    // Première ligne des cartes (bordure supérieure)
    for (int j = debut; j <= fin; j++) {
        for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
            printf("┌──────┐ ");
        }
        printf("   ");  // Espace entre les joueurs
    }
    printf("\n");
    
    // Deuxième ligne (CARD)
    for (int j = debut; j <= fin; j++) {
        for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
            printf("│ CARD │ ");
        }
        printf("   ");
    }
    printf("\n");
    
    // Troisième ligne (numéro de la carte)
    for (int j = debut; j <= fin; j++) {
        for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
            if (joueurs[j][i] == 99) {
                printf("│~~~~~~│ ");
            } else if (joueurs[j][i] < 0 || joueurs[j][i] > 9) {
                printf("│  %d  │ ", joueurs[j][i]);
            } else {
                printf("│   %d  │ ", joueurs[j][i]);
            }
        }
        printf("   ");
    }
    printf("\n");
    
    // Quatrième ligne (YARD)
    for (int j = debut; j <= fin; j++) {
        for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
            printf("│ YARD │ ");
        }
        printf("   ");
    }
    printf("\n");
    
    // Cinquième ligne (bordure inférieure)
    for (int j = debut; j <= fin; j++) {
        for (int i = indice_carte_debut; i <= indice_carte_fin; i++) {
            printf("└──────┘ ");
        }
        printf("   ");
    }
    printf("\n");
}

// Fonction pour afficher les défausses personnelles
void afficher_defausses(int defausses[], int debut, int fin) {
    // Bordure supérieure
    for (int j = debut; j <= fin; j++) {
        printf("         ┌──────┐             ");

    }
    printf("\n");
    
    // Ligne DEFAUSSE
    for (int j = debut; j <= fin; j++) {
        printf("         │DEFAU.│             ");
    }
    printf("\n");
    
    // Valeur de la carte
    for (int j = debut; j <= fin; j++) {
        if (defausses[j] == 99) {
            printf("         │~~~~~~│             ");
        } else if (defausses[j] < 0 || defausses[j] > 9) {
            printf("         │  %d  │             ", defausses[j]);
        } else {
            printf("         │   %d  │             ", defausses[j]);
        }
    }
    printf("\n");
    
    // Ligne JOUEUR
    for (int j = debut; j <= fin; j++) {
        printf("         │      │             ");
    }
    printf("\n");
    
    // Bordure inférieure
    for (int j = debut; j <= fin; j++) {
        printf("         └──────┘             ");
    }
    printf("\n");
}

// Fonction pour afficher les numéros des joueurs horizontalement
void afficher_numeros_joueurs(int debut, int fin) {
    for (int j = debut; j <= fin; j++) {
        printf("        ~Joueur %d~            ", j + 1);
    }
    printf("\n\n");
}

// Fonction pour afficher la pioche
void afficher_pioche() {
    printf("\n        ┌──────┐\n");
    printf("        │ CARD │\n");
    printf("        │~~~~~~│\n");
    printf("        │ YARD │\n");
    printf("        └──────┘\n");
    printf("         PIOCHE\n\n");
}

// Fonction principale pour afficher le jeu
void afficher_jeu(int joueurs[][6], int defausses[], int nombreJoueurs) {
    // Vérification que le nombre de joueurs est valide
    if (nombreJoueurs < 2 || nombreJoueurs > 8) {
        printf("Erreur: Le nombre de joueurs doit être entre 2 et 8.\n");
        return;
    }
    
    // Première ligne de joueurs (joueurs 1 à 4 ou moins)
    int premierGroupe = (nombreJoueurs > 4) ? 3 : nombreJoueurs - 1;
    
    // Pour chaque groupe de joueurs
    for (int groupe = 0; groupe < nombreJoueurs; groupe += 4) {
        int debut = groupe;
        int fin = (groupe + 3 < nombreJoueurs - 1) ? groupe + 3 : nombreJoueurs - 1;
        
        // Affichage des cartes (0-2) des joueurs
        afficher_ligne_cartes(joueurs, debut, fin, 0, 2);
        
        // Affichage des cartes (3-5) des joueurs
        afficher_ligne_cartes(joueurs, debut, fin, 3, 5);
        
        // Affichage des défausses personnelles
        afficher_defausses(defausses, debut, fin);
        
        // Numéros des joueurs
        afficher_numeros_joueurs(debut, fin);
    }
    
    // Afficher la pioche
    afficher_pioche();
}

int main() {
    // Exemple avec 6 joueurs
    int nombreJoueurs = 6;
    
    // Tableau pour stocker les cartes des joueurs (jusqu'à 8 joueurs, chacun avec 6 cartes)
    int joueurs[8][6] = {
        {-2, 5, 99, 12, 99, 0},     // Joueur 1
        {3, 7, 99, 8, 2, 99},       // Joueur 2
        {6, 99, 4, 1, 9, 99},       // Joueur 3
        {8, 3, 2, 7, 99, 5},        // Joueur 4
        {1, 4, 99, 9, 6, 3},        // Joueur 5
        {5, 99, 7, 4, 2, 8},         // Joueur 6
        {99, 99, 99, 99, 99, 99},   // Joueur 7 (vide)
        {0, 1, 2, 3, 4, 5}          // Joueur 8 (exemple)
    };
    
    // Défausses personnelles des joueurs
    int defausses[8] = {
        4,    // Défausse du joueur 1
        7,    // Défausse du joueur 2
        99,   // Défausse du joueur 3 (vide)
        2,    // Défausse du joueur 4
        8,    // Défausse du joueur 5
        3,     // Défausse du joueur 6
        99,   // Défausse du joueur 7 (vide)
        1     // Défausse du joueur 8
    };
    
    // Afficher le jeu
    afficher_jeu(joueurs, defausses, nombreJoueurs);
    
    return 0;
}