#include <stdio.h>
#include <stdlib.h>

// Définition des codes de couleur ANSI
#define RESET       "\033[0m"
#define NOIR        "\033[30m"
#define ROUGE       "\033[31m"
#define VERT        "\033[32m"
#define JAUNE       "\033[33m"
#define BLEU        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define BLANC       "\033[37m"
#define B_NOIR      "\033[1;30m"
#define B_ROUGE     "\033[1;31m"
#define B_VERT      "\033[1;32m"
#define B_JAUNE     "\033[1;33m"
#define B_BLEU      "\033[1;34m"
#define B_MAGENTA   "\033[1;35m"
#define B_CYAN      "\033[1;36m"
#define B_BLANC     "\033[1;37m"

// Fonction pour obtenir la couleur appropriée selon la valeur de la carte
const char* obtenir_couleur(int valeur) {
    if (valeur == 99) return BLANC; // Cartes non retournées en blanc
    else if (valeur == -2) return ROUGE;
    else if (valeur == -1) return B_ROUGE;
    else if (valeur == 0) return NOIR;
    else if (valeur == 1) return B_NOIR;
    else if (valeur == 2) return VERT;
    else if (valeur == 3) return B_VERT;
    else if (valeur == 4) return JAUNE;
    else if (valeur == 5) return B_JAUNE;
    else if (valeur == 6) return BLEU;
    else if (valeur == 7) return B_BLEU;
    else if (valeur == 8) return MAGENTA;
    else if (valeur == 9) return B_MAGENTA;
    else if (valeur == 10) return CYAN;
    else if (valeur == 11) return B_CYAN;
    else if (valeur == 12) return ROUGE;
    else if (valeur == 13) return B_ROUGE;
    else if (valeur == 14) return VERT;
    else if (valeur == 15) return B_VERT;
    else if (valeur == 16) return BLEU;
    else if (valeur == 17) return B_BLEU;
    else if (valeur == 18) return MAGENTA;
    else if (valeur == 19) return B_MAGENTA;
    else if (valeur == 20) return CYAN;
    else return BLANC; // Valeur par défaut
}

// Fonction pour afficher une ligne de cartes pour plusieurs joueurs
void afficher_ligne_cartes(int joueurs[][6], int debut, int fin, int indice_carte_debut, int indice_carte_fin) {
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
            if (joueurs[j][i] == 99) {
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

// Fonction pour afficher les défausses personnelles
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
        if (defausses[j] == 99) {
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

// Fonction pour afficher les numéros des joueurs horizontalement
void afficher_numeros_joueurs(int debut, int fin) {
    for (int j = debut; j <= fin; j++) {
        printf("        ~Joueur %d~            ", j + 1);
    }
    printf("\n\n");
}

// Fonction pour afficher la pioche
void afficher_pioche() {
    printf("\n        %s┌──────┐%s\n", BLANC, RESET);
    printf("        %s│ CARD │%s\n", BLANC, RESET);
    printf("        %s│~~~~~~│%s\n", BLANC, RESET);
    printf("        %s│ YARD │%s\n", BLANC, RESET);
    printf("        %s└──────┘%s\n", BLANC, RESET);
    printf("         PIOCHE\n\n");
}

// Fonction principale pour afficher le jeu
void afficher_jeu(int joueurs[][6], int defausses[], int nombreJoueurs) {
    // Vérification que le nombre de joueurs est valide
    if (nombreJoueurs < 2 || nombreJoueurs > 8) {
        printf("Erreur: Le nombre de joueurs doit être entre 2 et 8.\n");
        return;
    }
    
    // Pour chaque groupe de joueurs
    for (int groupe = 0; groupe < nombreJoueurs; groupe += 4) {
        int debut = groupe;
        int fin = (groupe + 3 < nombreJoueurs) ? groupe + 3 : nombreJoueurs - 1;
        
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
    // Pour Windows, décommenter cette ligne pour activer la prise en charge des couleurs ANSI
    // system("color");
    
    // Exemple avec 6 joueurs
    int nombreJoueurs = 6;
    
    // Tableau pour stocker les cartes des joueurs (jusqu'à 8 joueurs, chacun avec 6 cartes)
    int joueurs[8][6] = {
        {-2, 5, 99, 12, 99, 0},     // Joueur 1
        {3, 7, 99, 8, 2, 99},       // Joueur 2
        {6, 99, 4, 1, 9, 99},       // Joueur 3
        {8, 3, 2, 7, 99, 5},        // Joueur 4
        {1, 4, 99, 9, 6, 3},        // Joueur 5
        {5, 99, 7, 4, 2, 8},        // Joueur 6
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
        3,    // Défausse du joueur 6
        99,   // Défausse du joueur 7 (vide)
        1     // Défausse du joueur 8
    };
    
    // Afficher le jeu
    afficher_jeu(joueurs, defausses, nombreJoueurs);
    
    return 0;
}