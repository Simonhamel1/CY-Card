# Nom de l'exécutable
TARGET = fichier_program

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -g

# Fichiers sources et objets
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# Règle par défaut
all: $(TARGET)

# Création de l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation des fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers générés
clean:
	rm -f $(OBJS) $(TARGET)

# Nettoyage complet
distclean: clean
	rm -f *~