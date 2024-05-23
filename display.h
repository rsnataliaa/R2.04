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

// Fonction pour afficher un message d'erreur indiquant une adresse IP invalide.
// Le message est écrit dans le fichier spécifié par le paramètre file.
void printInvalidAddress(FILE *file);

// Fonction pour afficher une adresse IP et son masque de sous-réseau.
// Les adresses IP et masque sont passées sous forme de tableaux d'octets (uint8_t).
void printAddress(FILE *file, uint8_t *address, uint8_t *mask);

// Fonction pour afficher les adresses de réseau et d'hôte.
// Les adresses de réseau et d'hôte sont passées sous forme de tableaux d'octets (uint8_t).
void printHostNet(FILE *file, uint8_t *network, uint8_t *host);

// Fonction pour afficher le type de l'adresse IP.
// Le type est passé sous forme d'une chaîne de caractères.
void printAddressType(FILE *file, char type[15]);

// Fonction pour afficher la classe de l'adresse IP.
// La classe est passée sous forme d'une chaîne de caractères.
void printClass(FILE *file, char classString[]);