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
    // Déclaration des variables pour stocker l'adresse IP, les octets de l'IP et du masque, et les champs convertis en entier.
    char ip[MAX_LENGTH];
    char octetIP1[4], octetIP2[4], octetIP3[4], octetIP4[4], octetMask[3];
    uint8_t intFieldIP[4], intMaskField[4], network[4], host[4];
    char type[15], classString[20];

    // Ouverture du fichier en mode écriture.
    FILE *file = fopen("output.txt", "w");

    // Vérification de l'ouverture du fichier.
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return 1;
    }

    // Affichage et écriture dans le fichier des informations.
    printf("R2.04 : Titouan Helbert et Natalia Ros\n\n");
    fprintf(file, "R2.04 : Titouan Helbert et Natalia Ros\n\n");

    // Demande à l'utilisateur de saisir une adresse IP.
    printf("Entrez une adresse IP : ");
    fgets(ip, sizeof(ip), stdin);

    // Vérification de la validité de l'adresse IP.
    if (!isValidAddress(ip)) {
        printInvalidAddress(file); // Affichage d'un message d'erreur si l'adresse est invalide.
        return 1;
    }

    // Extraction des différents champs de l'adresse IP et du masque.
    extractAddress(ip, octetIP1, octetIP2, octetIP3, octetIP4, octetMask);

    // Conversion des champs de l'adresse IP et du masque en entiers.
    convertToInt(octetIP1, octetIP2, octetIP3, octetIP4, octetMask, intFieldIP, intMaskField);

    // Affichage de l'adresse IP et du masque en format entier.
    printAddress(file, intFieldIP, intMaskField);

    // Calcul des adresses de réseau et d'hôte.
    calculHostNetwork(intFieldIP, intMaskField, network, host);

    // Affichage des adresses de réseau et d'hôte.
    printHostNet(file, network, host);

    // Détermination et affichage du type d'adresse IP.
    typeIP(intFieldIP, type);
    printAddressType(file, type);

    // Détermination et affichage de la classe de l'adresse IP.
    classIp(intFieldIP[0], classString);
    printClass(file, classString);

    // Fermeture du fichier.
    fclose(file);

    return 0;
}