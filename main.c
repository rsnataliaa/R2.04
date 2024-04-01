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
#include <string.h>
#include "analyse_ip.h"
#include <stdint.h>

int main() {
    char ip[MAX_LENGTH];
    char mask[MAX_LENGTH];
    uint8_t octet[4];

//    printf("Entrez une adresse IP : ");
//    fgets(ip, sizeof(ip), stdin);
//    ip[strcspn(ip, "\n")] = 0;
//
//    if (!isValidAddress(ip)) {
//        printf("Adresse IP invalide\n");
//        return 1;
//    }
//
//    printf("Adresse IP valide\n");

    printf("Entrez un masque : ");
    fgets(mask, sizeof(mask), stdin);
    mask[strcspn(mask, "\n")] = 0;

    if (!isValidAddress(ip)) {
        printf("Masque invalide\n");
        return 1;
    }

    printf("Masque valide\n");

    extractIPAddress(ip, mask);

    return 0;
}