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
*  Nom du fichier : decode.h                                                  *
*                                                                             *
******************************************************************************/

#include <stdint.h>

void calculHostNetwork(uint8_t *intFieldIP, uint8_t *intFieldMask, uint8_t *network, uint8_t *host);

void typeIP(uint8_t *address, char type[15]);

void classIp(uint8_t firstOctet, char classString[]);