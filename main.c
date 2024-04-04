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
    char octetIP1[4], octetIP2[4], octetIP3[4], octetIP4[4], octetMask[3];
    uint8_t intFieldIP[4], intMaskField[4];

    char ip[] = "192.168.10.8/24";

//    printf("Entrez une adresse IP : ");
//    fgets(ip, sizeof(ip), stdin);

    if (!isValidAddress(ip)) {
        printf("Adresse invalide\n");
        return 1;
    }
//
    printf("Adresse IP valide\n");
    printf("Masque valide\n");

    extractAddress(ip, octetIP1, octetIP2, octetIP3, octetIP4, octetMask);

    printf("Adresse IP : %s.%s.%s.%s\n", octetIP1, octetIP2, octetIP3, octetIP4);
    printf("Masque de sous-réseau : /%s\n", octetMask);

    convertToInt(octetIP1, octetIP2, octetIP3, octetIP4, octetMask, intFieldIP, intMaskField);

    printf("IP INT : %d.%d.%d.%d\n", intFieldIP[0], intFieldIP[1], intFieldIP[2],
           intFieldIP[3]);
    printf("Masque INT : %d.%d.%d.%d\n", intMaskField[0], intMaskField[1], intMaskField[2],
           intMaskField[3]);

    return 0;
}