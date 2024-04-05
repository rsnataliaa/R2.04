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
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/

#include "extract_fields.h"
#include "decode.h"
#include "display.h"
#include <stdio.h>

int main() {
    char ip[MAX_LENGTH];
    char octetIP1[4], octetIP2[4], octetIP3[4], octetIP4[4], octetMask[3];
    uint8_t intFieldIP[4], intMaskField[4], network[4], host[4];
    char type[15], classString[20];

    FILE *file = fopen("output.txt", "w");

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
    }

    printf("R2.04 : Titouan Helbert et Natalia Ros\n\n");
    fprintf(file, "R2.04 : Titouan Helbert et Natalia Ros\n\n");

    printf("Entrez une adresse IP : ");
    fgets(ip, sizeof(ip), stdin);

    if (!isValidAddress(ip)) {
        printInvalidAddress(file);
        return 1;
    }

    extractAddress(ip, octetIP1, octetIP2, octetIP3, octetIP4, octetMask);

    convertToInt(octetIP1, octetIP2, octetIP3, octetIP4, octetMask, intFieldIP, intMaskField);

    printAddress(file, intFieldIP, intMaskField);

    calculHostNetwork(intFieldIP, intMaskField, network, host);

    printHostNet(file, network, host);

    typeIP(intFieldIP, type);

    printAddressType(file, type);

    classIp(intFieldIP[0], classString);

    printClass(file, classString);

    fclose(file);

    return 0;
}