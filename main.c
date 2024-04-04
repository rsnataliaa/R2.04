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
    uint32_t numericIP, numericMask;
    uint8_t octetIP[4], octetMask;

    char ip[] = "192.168.10.8/24";

//    printf("Entrez une adresse IP : ");
//    fgets(ip, sizeof(ip), stdin);

//    if (!isValidAddress(ip)) {
//        printf("Adresse IP invalide\n");
//        return 1;
//    }
//
//    printf("Adresse IP valide\n");
//    printf("Masque valide\n");

    extractAddress(ip, octetIP, &octetMask);

    printf("Adresse IP : %d.%d.%d.%d\n", octetIP[0], octetIP[1], octetIP[2], octetIP[3]);
    printf("Masque de sous-réseau : /%d\n", octetMask);

//    extractNumericAddress(ip, &numericIP, &numericMask);
//
//    printf("Numeric IP: %u\n", numericIP);
//    printf("Numeric Mask: %u\n", numericMask);

    return 0;
}