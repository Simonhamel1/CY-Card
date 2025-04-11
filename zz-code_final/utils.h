#ifndef UTILS_H
#define UTILS_H
 
#include <stdbool.h>

/* Input/Output Functions */
int readInt(int min, int max, const char *promptMessage, const char *errorMessage);
char* readString(char *buffer, int size, const char *promptMessage);
void pauseWithMessage(const char *message);

/* Random Number Generation */
void initRandom();
int getRandomNumber(int min, int max);
 
#endif // UTILS_H