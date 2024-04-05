/******************************************************************************
 *  ASR => 4R2.04                                                              *
 *******************************************************************************
 *                                                                             *
 *  N° de Sujet :     2                                                        *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Intitulé :Analyse d’adresses IP                                            *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Nom-prénom1 :ROS Natalia                                                   *
 *                                                                             *
 *  Nom-prénom2 :HELBERT Titouan                                               *
 *                                                                             *
 *******************************************************************************
 *                                                                             *
 *  Nom du fichier :SAE2.04                                                    *
 *                                                                             *
 ******************************************************************************/

#include "extract_fields.h"
#include "decode.h"
#include "display.h"

int main() {
//    char ip[MAX_LENGTH];
    char octetIP1[4], octetIP2[4], octetIP3[4], octetIP4[4], octetMask[3];
    uint8_t intFieldIP[4], intMaskField[4], network[4], host[4];
    char type[15];

//    char ip[] = "192.168.10.8/24";
    char ip[] = "224.0.0.1/0";

//    printf("Entrez une adresse IP : ");
//    fgets(ip, sizeof(ip), stdin);

    if (!isValidAddress(ip)) {
        printInvalidAddress();
        return 1;
    }

    extractAddress(ip, octetIP1, octetIP2, octetIP3, octetIP4, octetMask);

    convertToInt(octetIP1, octetIP2, octetIP3, octetIP4, octetMask, intFieldIP, intMaskField);

    printAddress(intFieldIP, intMaskField);

    calculHostNetwork(intFieldIP, intMaskField, network, host);

    printHostNet(network, host);

    decodeIp(intFieldIP, type);

    printAddressType(type);

    return 0;
}