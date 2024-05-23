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

// Fonction pour calculer les adresses de réseau et d'hôte à partir d'une adresse IP et d'un masque de sous-réseau.
// Les adresses IP et masque sont passées sous forme de tableaux d'octets (uint8_t).
// Les résultats sont stockés dans les tableaux network et host.
void calculHostNetwork(uint8_t *intFieldIP, uint8_t *intFieldMask, uint8_t *network, uint8_t *host);

// Fonction pour déterminer le type d'une adresse IP.
// Le type est stocké dans la chaîne de caractères type.
void typeIP(uint8_t *address, char type[15]);

// Fonction pour déterminer la classe d'une adresse IP en fonction de son premier octet.
// La classe est stockée dans la chaîne de caractères classString.
void classIp(uint8_t firstOctet, char classString[]);