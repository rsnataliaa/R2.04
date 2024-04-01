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
#include <ctype.h>
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

void extractIPAddress(char *ip, char *mask) {
    uint8_t octetIP[4], octetMask[4], networkAddress[4];

    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &octetIP[0], &octetIP[1], &octetIP[2], &octetIP[3]);
    sscanf(mask, "%hhu.%hhu.%hhu.%hhu", &octetMask[0], &octetMask[1], &octetMask[2], &octetMask[3]);

    for (int i = 0; i < 4; i++) {
        networkAddress[i] = octetIP[i] & octetMask[i];
    }

    printf("Network Address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2],
           networkAddress[3]);
}

