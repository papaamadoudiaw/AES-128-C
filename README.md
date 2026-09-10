# 🔐 AES-128-C

Implémentation complète d'AES-128 en langage C, réalisée dans le cadre de mon Master 2 Algèbre Appliquée et Cryptologie. L'objectif : comprendre et coder chaque brique de l'algorithme (SubBytes, ShiftRows, MixColumns, AddRoundKey, Key Schedule) à partir des spécifications du standard FIPS-197, sans utiliser de bibliothèque cryptographique existante.

## 👤 Auteur

**DIAW Papa Amadou**
Master 2 Algèbre Appliquée et Cryptologie
Université de Versailles Saint-Quentin (Université Paris-Saclay)

## 📁 Structure du projet
AES-128-C/

├── src/
|
│ ├── aes.h # Declarations des fonctions AES.
|
│ ├── aes.c # SubBytes, ShiftRows, MixColumns, AddRoundKey,
|
│ │ # Key Schedule, chiffrement et dechiffrement.
│ 
├── main.c # Tests de validation (vecteur NIST + cycle complet).
│ ├── chiffrer.c # Programme interactif de chiffrement.
|
│ └── dechiffrer.c # Programme interactif de dechiffrement.
|
├── .gitignore.
|
└── README.md.

## 🚀 Compilation et exécution

### Tests de validation

```bash
gcc -Wall -o main src/main.c src/aes.c
./main
```

### Chiffrement interactif

```bash
gcc -Wall -o chiffrer src/chiffrer.c src/aes.c
./chiffrer
```

### Dechiffrement interactif

```bash
gcc -Wall -o dechiffrer src/dechiffrer.c src/aes.c
./dechiffrer
```

## 📚 Fonctions implémentées

| Fonction | Rôle |
|---|---|
| `sub_bytes` / `inv_sub_bytes` | Substitution via la table S-box (et son inverse) |
| `shift_rows` / `inv_shift_rows` | Décalage circulaire des lignes de l'état |
| `mix_columns` / `inv_mix_columns` | Diffusion par mélange des colonnes (arithmétique GF(2^8)) |
| `add_round_key` | XOR de l'état avec la sous-clé du tour |
| `key_expansion` | Génération des 11 sous-clés de tour à partir de la clé maître |
| `aes128_encrypt` / `aes128_decrypt` | Assemblage complet du chiffrement et du dechiffrement |

## ✅ Validation

L'implémentation est vérifiée à l'aide du vecteur de test officiel AES-128 du NIST (clé et texte clair nuls) :

Texte clair : 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00

Clé : 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00

Chiffré : 66 e9 4b d4 ef 8a 2c 3b 88 4c fa 59 ca 34 2b 2e

Le cycle complet chiffrement → déchiffrement est également testé, confirmant que `dechiffrer(chiffrer(x)) == x` pour tout bloc `x`.

## 🧠 Notions mises en œuvre

- Arithmétique dans le corps fini GF(2^8) : multiplication (`xtime`), polynôme irréductible du standard AES
- Structure d'un réseau de substitution-permutation (S-box, permutation de lignes, diffusion par colonnes)
- Key Schedule : dérivation de 11 sous-clés de tour à partir d'une clé maître de 128 bits
- Manipulation bas niveau en C : pointeurs, arithmétique de pointeur, types de taille fixe (`uint8_t`)
- Méthodologie de validation par vecteurs de test de référence (NIST)

## 📄 Master

Projet académique à visée pédagogique.