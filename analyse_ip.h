#include <stdint.h>

#define MAX_LENGTH 20

int isValidAddress(char *adresse);
void extractAddress(char *ip, char *mask, uint8_t *octetIP, uint8_t *octetMask);
void extractNumericAddress(char *ip, char *mask, uint32_t *numericIP, uint32_t *numericMask);