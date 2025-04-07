CC = gcc
CFLAGS = -Wall -std=c99 -I./src  # Ajoutez -I pour que le compilateur trouve les fichiers .h
RM = del /Q  # Commande pour supprimer les fichiers sur Windows
SRC = src/carte.c src/joueur.c src/jeu.c main.c  # Liste des fichiers source
OBJ = $(SRC:.c=.o)  # Transformation des fichiers .c en .o
EXEC = cardyard  # Nom de l'exécutable

# Règle par défaut
all: $(EXEC)

# Lien des fichiers objets pour créer l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Règle de compilation des fichiers .c en .o
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	-$(RM) $(OBJ) $(EXEC)
