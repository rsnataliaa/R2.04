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
*  Nom du fichier : display.c                                                 *
*                                                                             *
******************************************************************************/

#include "display.h"
#include "decode.h"
#include <stdio.h>

void printInvalidAddress(FILE *file) {
    printf("Adresse invalide\n");
    fprintf(file, "Adresse invalide\n");
}

void printAddress(FILE *file, uint8_t *address, uint8_t *mask) {
    printf("Adresse IP : %d.%d.%d.%d\n", address[0], address[1], address[2], address[3]);
    printf("Masque de sous-réseau : %d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
    fprintf(file, "Adresse IP : %d.%d.%d.%d\n", address[0], address[1], address[2], address[3]);
    fprintf(file, "Masque de sous-réseau : %d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);
    printf("-------------------------------------\n");
    fprintf(file, "-------------------------------------\n");
}

void printHostNet(FILE *file, uint8_t *network, uint8_t *host) {
    printf("Réseau : ");
    printf("%d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Hôte : ");
    printf("%d.%d.%d.%d\n", host[0], host[1], host[2], host[3]);
    fprintf(file, "Réseau : ");
    fprintf(file, "%d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("-------------------------------------\n");
    fprintf(file, "-------------------------------------\n");
    fprintf(file, "Hôte : ");
    fprintf(file, "%d.%d.%d.%d\n", host[0], host[1], host[2], host[3]);
}

void printAddressType(FILE *file, char type[15]) {
    printf("Type : %s\n", type);
    fprintf(file, "Type : %s\n", type);
}

void printClass(FILE *file, char classString[]) {
    printf("Classe : %s\n", classString);
    fprintf(file, "Classe : %s\n", classString);
}