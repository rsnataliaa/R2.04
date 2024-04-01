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
#include <stdint.h>
#include "analyse_ip.h"

int main() {
//    char ip[MAX_LENGTH];
//    char mask[MAX_LENGTH];
    uint32_t numericIP, numericMask;

    char ip[] = "192.168.1.1";
    char mask[] = "255.255.255.0";

//    printf("Entrez une adresse IP : ");
//    fgets(ip, sizeof(ip), stdin);

    if (!isValidAddress(ip)) {
        printf("Adresse IP invalide\n");
        return 1;
    }

    printf("Adresse IP valide\n");

//    printf("Entrez un masque : ");
//    fgets(mask, sizeof(mask), stdin);

    if (!isValidAddress(mask)) {
        printf("Masque invalide\n");
        return 1;
    }

    printf("Masque valide\n");

    extractNumericAddress(ip, mask, &numericIP, &numericMask);

    printf("Numeric IP: %u\n", numericIP);
    printf("Numeric Mask: %u\n", numericMask);


    return 0;
}