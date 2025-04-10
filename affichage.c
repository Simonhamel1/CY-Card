#include <stdio.h>
#include <stdlib.h>

// Affiche une carte face visible
void afficher_carte_visible() {
    printf("┌─────────┐\n");
    printf("│ CARD    │\n");
    printf("│ ------  │\n");
    printf("│ YARD    │\n");
    printf("└─────────┘\n");
}

// Affiche une carte face cachée
void afficher_carte_cachee() {
    printf("┌─────────┐\n");
    printf("│░░░░░░░░░│\n");
    printf("│░░░░░░░░░│\n");
    printf("│░░░░░░░░░│\n");
    printf("└─────────┘\n");
}

// Affiche une défausse vide
void afficher_defausse_vide() {
    printf("┌─────────┐\n");
    printf("│         │\n");
    printf("│         │\n");
    printf("│         │\n");
    printf("└─────────┘\n");
}

// Fonction pour afficher une carte avec un décalage
void afficher_carte_avec_decalage(int decalage, int est_cachee) {
    // Décalage initial
    for (int i = 0; i < decalage; i++) {
        printf(" ");
    }
    
    printf("┌─────────┐\n");
    
    for (int i = 0; i < decalage; i++) {
        printf(" ");
    }
    
    if (est_cachee) {
        printf("│░░░░░░░░░│\n");
        
        for (int i = 0; i < decalage; i++) {
            printf(" ");
        }
        
        printf("│░░░░░░░░░│\n");
        
        for (int i = 0; i < decalage; i++) {
            printf(" ");
        }
        
        printf("│░░░░░░░░░│\n");
    } else {
        printf("│ CARD    │\n");
        
        for (int i = 0; i < decalage; i++) {
            printf(" ");
        }
        
        printf("│ ------  │\n");
        
        for (int i = 0; i < decalage; i++) {
            printf(" ");
        }
        
        printf("│ YARD    │\n");
    }
    
    for (int i = 0; i < decalage; i++) {
        printf(" ");
    }
    
    printf("└─────────┘\n");
}

// Fonction pour afficher une rangée horizontale de cartes
void afficher_rangee_cartes(int nombre_cartes, int decalage, int est_cachee) {
    // Première ligne des cartes
    for (int i = 0; i < decalage; i++) {
        printf(" ");
    }
    
    for (int j = 0; j < nombre_cartes; j++) {
        printf("┌─────────┐  ");
    }
    printf("\n");
    
    // Lignes du milieu des cartes
    for (int ligne = 0; ligne < 3; ligne++) {
        for (int i = 0; i < decalage; i++) {
            printf(" ");
        }
        
        for (int j = 0; j < nombre_cartes; j++) {
            if (est_cachee) {
                printf("│░░░░░░░░░│  ");
            } else if (ligne == 1) {
                printf("│ ------  │  ");
            } else {
                printf("│ CARD    │  ");
            }
        }
        printf("\n");
    }
    
    // Dernière ligne des cartes
    for (int i = 0; i < decalage; i++) {
        printf(" ");
    }
    
    for (int j = 0; j < nombre_cartes; j++) {
        printf("└─────────┘  ");
    }
    printf("\n");
}

// Fonction pour afficher une rangée de défausses
void afficher_rangee_defausses(int nombre_defausses, int decalage) {
    // Première ligne des défausses
    for (int i = 0; i < decalage; i++) {
        printf(" ");
    }
    
    for (int j = 0; j < nombre_defausses; j++) {
        printf("┌─────────┐  ");
    }
    printf("\n");
    
    // Lignes du milieu des défausses
    for (int ligne = 0; ligne < 3; ligne++) {
        for (int i = 0; i < decalage; i++) {
            printf(" ");
        }
        
        for (int j = 0; j < nombre_defausses; j++) {
            printf("│         │  ");
        }
        printf("\n");
    }
    
    // Dernière ligne des défausses
    for (int i = 0; i < decalage; i++) {
        printf(" ");
    }
    
    for (int j = 0; j < nombre_defausses; j++) {
        printf("└─────────┘  ");
    }
    printf("\n");
}

// Fonction principale pour afficher la zone de jeu complète
void afficher_zone_de_jeu(int nombre_joueurs, int cartes_par_joueur) {
    if (nombre_joueurs < 2 || nombre_joueurs > 8) {
        printf("Le nombre de joueurs doit être entre 2 et 8.\n");
        return;
    }
    
    int decalage_central = 30; // Décalage pour centrer les éléments
    
    printf("\n\n");
    
    // Distribution des joueurs autour du cercle en fonction du nombre de joueurs
    
    // Joueur(s) du haut (1/3 des joueurs, minimum 1)
    int joueurs_haut = (nombre_joueurs >= 3) ? nombre_joueurs / 3 : 1;
    int cartes_par_ligne = (cartes_par_joueur > 4) ? cartes_par_joueur / 2 : cartes_par_joueur;
    int reste_cartes = (cartes_par_joueur > 4) ? cartes_par_joueur - cartes_par_ligne : 0;
    
    // Affichage des joueurs du haut
    for (int j = 0; j < joueurs_haut; j++) {
        int decalage_joueur = decalage_central - ((cartes_par_ligne * 11) / 2) + (j * 15);
        afficher_rangee_cartes(cartes_par_ligne, decalage_joueur, 1);
        
        if (reste_cartes > 0) {
            afficher_rangee_cartes(reste_cartes, decalage_joueur + 5, 1);
        }
        printf("\n");
    }
    
    // Calcul du nombre de joueurs à gauche et à droite
    int joueurs_restants = nombre_joueurs - joueurs_haut;
    int joueurs_gauche = joueurs_restants / 2;
    int joueurs_droite = joueurs_restants - joueurs_gauche;
    
    // Affichage des joueurs de gauche et de droite
    printf("\n");
    
    // Hauteur maximale des cartes côté pour un visuel équilibré
    int hauteur_cotes = (joueurs_gauche > joueurs_droite) ? joueurs_gauche : joueurs_droite;
    hauteur_cotes = hauteur_cotes * 2; // Pour espacer visuellement
    
    for (int ligne = 0; ligne < hauteur_cotes; ligne++) {
        // Joueurs de gauche
        if (ligne < joueurs_gauche * 2 && ligne % 2 == 0) {
            int joueur_id = ligne / 2;
            afficher_rangee_cartes(cartes_par_ligne / 2, 5, 1);
        } else {
            printf("\n");
        }
        
        // Joueurs de droite (côté opposé)
        if (ligne < joueurs_droite * 2 && ligne % 2 == 0) {
            int joueur_id = ligne / 2;
            afficher_rangee_cartes(cartes_par_ligne / 2, decalage_central * 2 - 20, 1);
        }
    }
    
    // Pioche centrale
    printf("\n");
    afficher_carte_avec_decalage(decalage_central, 1);
    printf("\n");
    
    // Affichage des défausses de chaque joueur
    printf("\n");
    for (int j = 0; j < nombre_joueurs; j++) {
        int decalage_defausse = decalage_central - 5 + (j * 15 - ((nombre_joueurs * 15) / 2));
        if (j % 2 == 0) {
            afficher_carte_avec_decalage(decalage_defausse, 0);  // Défausse visible
        } else {
            afficher_carte_avec_decalage(decalage_defausse, 1);  // Défausse cachée
        }
    }
    
    // Joueur(s) du bas (1/3 des joueurs, minimum 1 si 2 joueurs)
    int joueurs_bas = (nombre_joueurs == 2) ? 1 : nombre_joueurs - (joueurs_haut + joueurs_gauche + joueurs_droite);
    
    printf("\n");
    for (int j = 0; j < joueurs_bas; j++) {
        int decalage_joueur = decalage_central - ((cartes_par_ligne * 11) / 2) + (j * 15);
        
        if (reste_cartes > 0) {
            afficher_rangee_cartes(reste_cartes, decalage_joueur + 5, 1);
        }
        
        afficher_rangee_cartes(cartes_par_ligne, decalage_joueur, 1);
    }
    
    printf("\n\n");
}

int main() {
    int nombre_joueurs, cartes_par_joueur;
    
    // Demande du nombre de joueurs
    do {
        printf("Entrez le nombre de joueurs (2-8): ");
        scanf("%d", &nombre_joueurs);
        
        if (nombre_joueurs < 2 || nombre_joueurs > 8) {
            printf("Le nombre de joueurs doit être entre 2 et 8.\n");
        }
    } while (nombre_joueurs < 2 || nombre_joueurs > 8);
    
    // Nombre de cartes par joueur
    cartes_par_joueur = 6;  // Par défaut comme dans l'exemple
    
    // Affichage de la zone de jeu
    afficher_zone_de_jeu(nombre_joueurs, cartes_par_joueur);
    
    return 0;
}