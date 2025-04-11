# Makefile pour le projet Card Yard

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = 

# Fichiers source et objets
SRCS = display.c utils.c save.c card.c player.c game.c main.c
OBJS = $(SRCS:.c=.o)
TARGET = card_yard

# Dossiers
SAVE_DIR = saves

# Règle par défaut
all: directories $(TARGET)

# Créer les répertoires nécessaires
directories:
	mkdir -p $(SAVE_DIR)

# Lier le programme
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Règle générique pour compiler les fichiers source
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Dépendances entre fichiers - Assurez-vous que display.h est compilé en premier
display.o: display.c display.h 
utils.o: utils.c utils.h display.h
save.o: save.c save.h game.h display.h utils.h
card.o: card.c card.h game.h utils.h
player.o: player.c player.h game.h card.h display.h utils.h
game.o: game.c game.h card.h player.h display.h utils.h save.h
main.o: main.c game.h display.h player.h card.h utils.h save.h

# Nettoyer le projet
clean:
	rm -f $(OBJS) $(TARGET)

# Nettoyer le projet et les sauvegardes
cleanall: clean
	rm -rf $(SAVE_DIR)

# Exécuter le programme
run: all
	./$(TARGET)

# Pour éviter les conflits avec des fichiers du même nom
.PHONY: all clean cleanall run directories