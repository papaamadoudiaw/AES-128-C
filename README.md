# AES-128-C

Implémentation complète d'AES-128 en langage C, développée dans un cadre d'apprentissage personnel en complément de mon cursus de Master 2 Algèbre Appliquée et Cryptologie. L'objectif : comprendre et implémenter chaque brique de l'algorithme (SubBytes, ShiftRows, MixColumns, AddRoundKey, Key Schedule) à partir des spécifications du standard FIPS-197, sans recourir à une bibliothèque cryptographique existante.

## Auteur

**DIAW Papa Amadou**
Master 2 Algèbre Appliquée et Cryptologie
Université de Versailles Saint-Quentin (Université Paris-Saclay)

## Contexte

Ce projet a été réalisé pour consolider par la pratique les notions théoriques vues en cours de cryptologie : arithmétique dans les corps finis GF(2^8), structure d'un chiffrement par bloc (substitution-permutation), et le fonctionnement interne du standard AES tel que défini par le NIST (FIPS-197).

## Contenu du projet

- Un moteur AES-128 complet (chiffrement **et** déchiffrement), validé face aux vecteurs de test officiels du NIST
- `chiffrer` : programme interactif demandant un message et une clé, retournant le bloc chiffré
- `dechiffrer` : programme interactif demandant un chiffré (en hexadécimal) et une clé, retrouvant le message d'origine

## Structure du projet :src/
├── aes.h # Déclarations des fonctions AES
├── aes.c # Implémentation : SubBytes, ShiftRows, MixColumns, AddRoundKey,
│ # Key Schedule, chiffrement et déchiffrement complets
├── main.c # Tests de validation (vecteur NIST + cycle chiffrer/déchiffrer)
├── chiffrer.c # Programme interactif de chiffrement
└── dechiffrer.c # Programme interactif de déchiffrement

## Compilation et utilisation

```bash
# Tests de validation
gcc -Wall -o main src/main.c src/aes.c
./main

# Chiffrement interactif
gcc -Wall -o chiffrer src/chiffrer.c src/aes.c
./chiffrer

# Dechiffrement interactif
gcc -Wall -o dechiffrer src/dechiffrer.c src/aes.c
./dechiffrer
```

## Validation

L'implémentation est vérifiée à l'aide du vecteur de test officiel AES-128 du NIST (clé et texte clair nuls) :
Texte clair : 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Clé : 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Chiffré : 66 e9 4b d4 ef 8a 2c 3b 88 4c fa 59 ca 34 2b 2e

Le cycle complet chiffrement → déchiffrement est également testé, confirmant que `dechiffrer(chiffrer(x)) == x` pour tout bloc `x`.

## Notions mises en œuvre

- Arithmétique dans le corps fini GF(2^8) : multiplication (`xtime`), polynôme irréductible du standard AES
- Structure d'un réseau de substitution-permutation (S-box, permutation de lignes, diffusion par colonnes)
- Key Schedule : dérivation de 11 sous-clés de tour à partir d'une clé maître de 128 bits
- Manipulation bas niveau en C : pointeurs, arithmétique de pointeur, types de taille fixe (`uint8_t`)
- Méthodologie de validation par vecteurs de test de référence (NIST)

## Licence

Projet académique à visée pédagogique.