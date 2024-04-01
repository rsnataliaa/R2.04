#include <stdint.h>

#define MAX_LENGTH 20

int isValidAddress(char *adresse);
void extractAddress(char *ip, char *mask);
void extractNumericAddress(char *ip, char *mask, uint32_t *numericIP, uint32_t *numericMask);