#include <stdio.h>
#include <locale.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include "jeu.h"

int main() {
    // Active la locale pour l'UTF-8
    setlocale(LC_ALL, "");
#ifdef _WIN32
    // Configure la sortie console en UTF-8
    SetConsoleOutputCP(CP_UTF8);
#endif
    
    int nb_joueurs;
    printf("Bienvenue dans CardYard !\n");
    printf("Entrez le nombre de joueurs (2-8): ");
    scanf("%d", &nb_joueurs);
    
    Jeu jeu = creer_jeu(nb_joueurs);
    initialiser_pioche(&jeu);
    
    // Boucle principale du jeu
    while (1) {
        jouer_tour(&jeu);
    }
    
    return 0;
}
