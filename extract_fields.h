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
*  Nom du fichier : extract_fields.h                                          *
*                                                                             *
******************************************************************************/

#include <stdint.h>

#define MAX_LENGTH 20
#define MAX_FIELD 5

int isValidAddress(char *adresse);

void extractAddress(char *ip, char octetIP1[4], char octetIP2[4], char octetIP3[4],
                    char octetIP4[4], char octetMask[3]);

void convertToInt(char *octetIP1, char *octetIP2, char *octetIP3, char *octetIP4, char *octetMask,
                  uint8_t intFieldIP[4], uint8_t intFieldMask[4]);