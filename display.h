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
*  Nom du fichier : display.h                                                 *
*                                                                             *
******************************************************************************/

#include <stdint.h>
#include <stdio.h>

void printInvalidAddress(FILE *file);

void printAddress(FILE *file, uint8_t *address, uint8_t *mask);

void printHostNet(FILE *file, uint8_t *network, uint8_t *host);

void printAddressType(FILE *file, char type[15]);

void printClass(FILE *file, char classString[]);