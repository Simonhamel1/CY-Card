#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"

void sauvegarder(Jeu jeu) {
    FILE* fichier = fopen("sauvegarde.txt", "wb");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier de sauvegarde.\n");
        return;
    }
    
    fwrite(&jeu, sizeof(Jeu), 1, fichier);
    fclose(fichier);
}

Jeu restaurer() {
    Jeu jeu;
    FILE* fichier = fopen("sauvegarde.txt", "rb");
    if (fichier == NULL) {
        printf("Erreur lors de la restauration du fichier de sauvegarde.\n");
        return jeu;
    }

    fread(&jeu, sizeof(Jeu), 1, fichier);
    fclose(fichier);
    return jeu;
}
