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
*  Nom du fichier : decode.c                                                  *
*                                                                             *
******************************************************************************/

#include "decode.h"
#include <string.h>

void calculHostNetwork(uint8_t *intFieldIP, uint8_t *intFieldMask, uint8_t *network, uint8_t *host) {
    for (int i = 0; i < 4; ++i) {
        network[i] = intFieldIP[i] & intFieldMask[i];
    }

    for (int i = 0; i < 4; ++i) {
        host[i] = intFieldIP[i] & ~intFieldMask[i];
    }
}

void typeIP(uint8_t *address, char type[15]) {
    if (address[0] == 10 ||
        (address[0] == 172 && (address[1] >= 16 && address[1] <= 31)) ||
        (address[0] == 192 && address[1] == 168)) {
        strcpy(type, "Privé");
    } else if (address[0] == 127) {
        strcpy(type, "Localhost");
    } else if (address[3] == 255) {
        strcpy(type, "Broadcast");
    } else if (address[0] >= 224 && address[0] <= 239) {
        strcpy(type, "Multicast");
    } else if ((address[0] == 0) ||
               (address[0] >= 224 && address[0] <= 239) ||
                       (address[0] == 255 && address[1] == 255 && address[2] == 255 && address[3] == 255)) {
        strcpy(type, "Erreur");
    } else {
        strcpy(type, "Publique");
    }
}

void classIp(uint8_t firstOctet, char classString[]) {
    if (firstOctet >= 0 && firstOctet <= 127) {
        strcpy(classString, "A");
    } else if (firstOctet >= 128 && firstOctet <= 191) {
        strcpy(classString, "B");
    } else if (firstOctet >= 192 && firstOctet <= 223) {
        strcpy(classString, "C");
    } else if (firstOctet >= 224 && firstOctet <= 239) {
        strcpy(classString, "D");
    } else if (firstOctet >= 240 && firstOctet <= 255) {
        strcpy(classString, "E");
    } else {
        strcpy(classString, "Erreur");
    }
}