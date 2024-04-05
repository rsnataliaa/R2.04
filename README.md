
# R2.04
### **Titouan Helbert et Natalia Ros**
## Projet 2 : Analyse d’adresses IP

### Objectif de l'application développée

Ce programme en langage C est conçu pour analyser les adresses IP. Il comprend plusieurs étapes, notamment la recherche du format des adresses IP et des masques réseau, l'identification des fonctions nécessaires, le développement de ces fonctions, et enfin la construction du programme principal pour répondre au sujet du projet.

## Fichiers inclus

- `main.c`: Programme principal.
- `decode.c`: Implémentation des fonctions pour décoder les adresses IP et les masques réseau.
- `decode.h`: Déclarations des fonctions de décodage.
- `display.c`: Implémentation des fonctions pour afficher les résultats.
- `display.h`: Déclarations des fonctions d'affichage.
- `extract_fields.c`: Implémentation des fonctions pour extraire les champs des adresses IP.
- `extract_fields.h`: Déclarations des fonctions d'extraction de champs.
- `makefile`: Fichier Makefile pour la compilation.
- `output.txt`: Fichier texte généré avec les résultats.

## Compilation et exécution

Pour compiler le projet, exécutez la commande suivante dans votre terminal : `make all`

Une fois la compilation terminée, exécutez le programme en utilisant la commande : `./analyser`

Les résultats seront générés dans le fichier `output.txt`.

## Documentation des fonctions

### Fichier `extract_fields.h` :

#### `int isValidAddress(char *adresse)`

Cette fonction vérifie si une adresse IP donnée est valide.

- Paramètres :
  - `adresse` : Pointeur vers la chaîne de caractères représentant l'adresse IP.
- Retour :
  - `int` : 1 si l'adresse est valide, 0 sinon.

#### `void extractAddress(char *ip, char octetIP1[4], char octetIP2[4], char octetIP3[4], char octetIP4[4], char octetMask[3])`

Cette fonction extrait les octets de l'adresse IP et du masque réseau.

- Paramètres :
  - `ip` : Pointeur vers la chaîne de caractères représentant l'adresse IP.
  - `octetIP1` à `octetMask` : Tableaux de caractères pour stocker les octets extraits.
  
#### `void convertToInt(char *octetIP1, char *octetIP2, char *octetIP3, char *octetIP4, char *octetMask, uint8_t intFieldIP[4], uint8_t intFieldMask[4])`

Cette fonction convertit les octets de l'adresse IP et du masque réseau en entiers.

- Paramètres :
  - `octetIP1` à `octetIP4` : Octets de l'adresse IP.
  - `octetMask` : Octet du masque réseau.
  - `intFieldIP` : Tableau d'entiers pour stocker les octets de l'adresse IP convertis.
  - `intFieldMask` : Tableau d'entiers pour stocker les octets du masque réseau convertis.

### Fichier decode.h :

#### `void calculHostNetwork(uint8_t *intFieldIP, uint8_t *intFieldMask, uint8_t *network, uint8_t *host)`

Cette fonction calcule le réseau et l'hôte à partir des octets de l'adresse IP et du masque réseau.

- Paramètres :
  - `intFieldIP` : Tableau d'entiers représentant les octets de l'adresse IP.
  - `intFieldMask` : Tableau d'entiers représentant les octets du masque réseau.
  - `network` : Pointeur vers le tableau où sera stocké le réseau calculé.
  - `host` : Pointeur vers le tableau où sera stocké l'hôte calculé.

#### `void typeIP(uint8_t *address, char type[15])`

Cette fonction détermine le type d'adresse IP (publique, privée, etc.).

- Paramètres :
  - `address` : Tableau d'entiers représentant l'adresse IP.
  - `type` : Chaîne de caractères pour stocker le type d'adresse.

#### `void classIp(uint8_t firstOctet, char classString[])`

Cette fonction détermine la classe de l'adresse IP (A, B, C, etc.).

- Paramètres :
  - `firstOctet` : Premier octet de l'adresse IP.
  - `classString` : Chaîne de caractères pour stocker la classe.

### Fichier display.h :

#### `void printInvalidAddress(FILE *file)`

Cette fonction imprime un message indiquant qu'une adresse IP est invalide.

- Paramètres :
  - `file` : Pointeur vers le fichier où imprimer le message.

#### `void printAddress(FILE *file, uint8_t *address, uint8_t *mask)`

Cette fonction imprime une adresse IP avec son masque réseau.

- Paramètres :
  - `file` : Pointeur vers le fichier où imprimer l'adresse.
  - `address` : Tableau d'entiers représentant l'adresse IP.
  - `mask` : Tableau d'entiers représentant le masque réseau.

#### `void printHostNet(FILE *file, uint8_t *network, uint8_t *host)`

Cette fonction imprime le réseau et l'hôte.

- Paramètres :
  - `file` : Pointeur vers le fichier où imprimer le réseau et l'hôte.
  - `network` : Tableau d'entiers représentant le réseau.
  - `host` : Tableau d'entiers représentant l'hôte.

#### `void printAddressType(FILE *file, char type[15])`

Cette fonction imprime le type d'adresse IP.

- Paramètres :
  - `file` : Pointeur vers le fichier où imprimer le type d'adresse.
  - `type` : Chaîne de caractères représentant le type d'adresse.

#### `void printClass(FILE *file, char classString[])`

Cette fonction imprime la classe de l'adresse IP.

- Paramètres :
  - `file` : Pointeur vers le fichier où imprimer la classe d'adresse.
  - `classString` : Chaîne de caractères représentant la classe d'adresse.

## Dépôt GitLab

[Lien vers le dépôt](https://gitlab.info.iut-tlse3.fr/hlt5003a/r2.04)