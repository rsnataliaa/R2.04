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

// Définition des constantes pour la longueur maximale de l'adresse IP et des champs.
#define MAX_LENGTH 20
#define MAX_FIELD 5

// Fonction pour vérifier si une adresse IP est valide.
// Retourne 1 si l'adresse est valide, 0 sinon.
int isValidAddress(char *adresse);

// Fonction pour extraire les octets de l'adresse IP et du masque de sous-réseau à partir de la chaîne d'entrée.
// Les résultats sont stockés dans les paramètres octetIP1, octetIP2, octetIP3, octetIP4 et octetMask.
void extractAddress(char *ip, char octetIP1[4], char octetIP2[4], char octetIP3[4],
                    char octetIP4[4], char octetMask[3]);

// Fonction pour convertir les octets de l'adresse IP et du masque de sous-réseau de chaînes de caractères en entiers.
// Les résultats sont stockés dans les tableaux intFieldIP et intFieldMask.
void convertToInt(char *octetIP1, char *octetIP2, char *octetIP3, char *octetIP4, char *octetMask,
                  uint8_t intFieldIP[4], uint8_t intFieldMask[4]);