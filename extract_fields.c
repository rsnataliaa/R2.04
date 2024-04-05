/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 2                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Analyse d’adresses IP                                           *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : Titouan Helbert                                              *
*                                                                             *
*  Nom-prénom2 : Natalia Ros                                                  *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : extract_fields.c                                          *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extract_fields.h"
#include <stdint.h>

int isValidAddress(char *adresse) {
    char *new_adr = malloc(MAX_LENGTH);
    strcpy(new_adr, adresse);
    const char *separators = "./";
    char *ptr = strtok(new_adr, separators);
    int num_octets = 1;

    while (ptr != NULL) {
        if (num_octets == 5) {
            int subnet_value = atoi(ptr);
            if (subnet_value < 0 || subnet_value > 32) {
                return 0;
            }
        }
        int octet = atoi(ptr);
        if (octet < 0 || octet > 255) {
            return 0;
        }
        num_octets++;
        ptr = strtok(NULL, separators);
    }

    if (num_octets != MAX_FIELD + 1) {
        return 0;
    }

    return 1;
}

void extractAddress(char *ip, char octetIP1[4], char octetIP2[4], char octetIP3[4],
                    char octetIP4[4], char octetMask[3]) {
    const char *separators = "./";
    char *ptr = strtok(ip, separators);
    int num_octets = 1;
    while (ptr != NULL) {
        switch (num_octets) {
            case 1:
                sscanf(ptr, "%s", octetIP1);
                break;
            case 2:
                sscanf(ptr, "%s", octetIP2);
                break;
            case 3:
                sscanf(ptr, "%s", octetIP3);
                break;
            case 4:
                sscanf(ptr, "%s", octetIP4);
                break;
            case 5:
                sscanf(ptr, "%s", octetMask);
                break;
        }
        num_octets++;
        ptr = strtok(NULL, separators);
    }
}

void convertToInt(char *octetIP1, char *octetIP2, char *octetIP3, char *octetIP4, char *octetMask,
                  uint8_t intFieldIP[4], uint8_t intFieldMask[4]) {
    for (int i = 1; i < 5; i++) {
        switch (i) {
            case 1:
                intFieldIP[i - 1] = atoi(octetIP1);
                break;
            case 2:
                intFieldIP[i - 1] = atoi(octetIP2);
                break;
            case 3:
                intFieldIP[i - 1] = atoi(octetIP3);
                break;
            case 4:
                intFieldIP[i - 1] = atoi(octetIP4);
                break;
        }
    }

    uint8_t octetMaskInt = atoi(octetMask);
    for (int i = 0; i < 4; i++) {
        if (octetMaskInt >= 8) {
            intFieldMask[i] = 255;
            octetMaskInt -= 8;
        } else if (octetMaskInt > 0) {
            intFieldMask[i] = (uint8_t) (255 << (8 - octetMaskInt));
            octetMaskInt = 0;
        } else {
            intFieldMask[i] = 0;
        }
    }
}