CC = gcc
CFLAGS = -Wall -std=c99 -I./src  # Pour que le compilateur trouve les fichiers d'en-tête
# Pour un usage multi-plateforme, utilisez rm (disponible sous Git Bash)
RM = rm -f
SRC = src/carte.c src/joueur.c src/jeu.c main.c
OBJ = $(SRC:.c=.o)
EXEC = cardyard

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-$(RM) $(OBJ) $(EXEC)
