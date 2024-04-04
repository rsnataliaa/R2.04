#include <stdint.h>

#define MAX_LENGTH 20

int isValidAddress(char *adresse);
void extractAddress(char *ip, uint8_t *octetIP, uint8_t *octetMask);
void convertToInt(uint8_t *octetIP, uint8_t octetMask, uint8_t *intFieldIP, uint8_t *intField);