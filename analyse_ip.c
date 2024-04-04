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
    int num_octets = 1;

    while (ptr != NULL) {
        if (strchr(ptr, '/') != NULL) {
            char *subnet = strtok(ptr, "/");
            int subnet_value = atoi(subnet);
            if (subnet_value < 0 || subnet_value > 32) {
                return 0;
            }
            break;
        }
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

void extractAddress(char *ip, uint8_t *octetIP, uint8_t *octetMask) {
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu/%hhu", &octetIP[0], &octetIP[1], &octetIP[2], &octetIP[3], octetMask);
}

void convertToInt(uint8_t *octetIP, uint8_t octetMask, uint8_t *intFieldIP, uint8_t *intField) {
    for (int i = 0; i < 4; i++) {
        intFieldIP[i] = octetIP[i];
    }

    for (int i = 0; i < 4; i++) {
        if (octetMask >= 8) {
            intField[i] = 255;
            octetMask -= 8;
        } else if (octetMask > 0) {
            intField[i] = (uint8_t) (255 << (8 - octetMask));
            octetMask = 0;
        } else {
            intField[i] = 0;
        }
    }
}