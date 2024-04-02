/******************************************************************************
 *  ASR => 4R2.04                                                              *
 *******************************************************************************
 *                                                                             *
 *  N° de Sujet :     2                                                        *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Intitulé :Analyse d’adresses IP                                            *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Nom-prénom1 :ROS Natalia                                                   *
 *                                                                             *
 *  Nom-prénom2 :HELBERT Titouan                                               *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Nom du fichier :SAE2.04                                                    *
 *                                                                             *
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analyse_ip.h"
#include <stdint.h>

int isValidAddress(char *adresse) {
    char *ptr = strtok(adresse, ".");
    int num_octets = 0;

    while (ptr != NULL) {
        int octet = atoi(ptr);
        if (octet < 0 || octet > 255) {
            return 0;
        }
        num_octets++;
        ptr = strtok(NULL, ".");
    }

    if (num_octets != 4) {
        return 0;
    }

    return 1;
}

void extractAddress(char *ip, char *mask, uint8_t *octetIP, uint8_t *octetMask) {
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &octetIP[0], &octetIP[1], &octetIP[2], &octetIP[3]);
    sscanf(mask, "%hhu.%hhu.%hhu.%hhu", &octetMask[0], &octetMask[1], &octetMask[2], &octetMask[3]);

//    for (int i = 0; i < 4; i++) {
//        address[i] = octetIP[i] & octetMask[i];
//    }
}

void extractNumericAddress(char *ip, char *mask, uint32_t *numericIP, uint32_t *numericMask) {
    uint8_t octetIP[4], octetMask[4];

    extractAddress(ip, mask, octetIP, octetMask);

    *numericIP = (uint32_t) (octetIP[0]) << 24 |
                 (uint32_t) (octetIP[1]) << 16 |
                 (uint32_t) (octetIP[2]) << 8 |
                 (uint32_t) (octetIP[3]);

    *numericMask = (uint32_t) (octetMask[0]) << 24 |
                   (uint32_t) (octetMask[1]) << 16 |
                   (uint32_t) (octetMask[2]) << 8 |
                   (uint32_t) (octetMask[3]);
}