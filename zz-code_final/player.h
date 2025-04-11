#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"

// Function to initialize players
bool initializePlayers(GameState *game);

// Function to handle a player's turn
bool playerTurn(GameState *game);

// Function to sort players by their scores
void sortPlayersByScore(GameState *game, int sortedIndices[], int scores[]);

// Function to display player scores
void displayPlayerScores(GameState *game, int sortedIndices[], int scores[]);

// Function to ask a player for a card exchange
int askPlayerForCardExchange(GameState *game, int drawnCard);

// Function to ask a player for their draw choice
int askPlayerForDrawChoice(GameState *game);

#endif // PLAYER_H