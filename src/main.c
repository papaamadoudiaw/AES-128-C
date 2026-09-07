#include <stdio.h>
#include <stdint.h>
#include "aes.h"

void afficher_bloc(const uint8_t *bloc) {
    for (int i = 0; i < 16; i++) {
        printf("%02x ", bloc[i]);
    }
    printf("\n");
}

int comparer_blocs(const uint8_t *a, const uint8_t *b) {
    for (int i = 0; i < 16; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    uint8_t texte_original[16] = {
        0x32, 0x88, 0x31, 0xe0, 0x43, 0x5a, 0x31, 0x37,
        0xf6, 0x30, 0x98, 0x07, 0xa8, 0x8d, 0xa2, 0x34
    };
    uint8_t cle[16] = {
        0x2b, 0x28, 0xab, 0x09, 0x7e, 0xae, 0xf7, 0xcf,
        0x15, 0xd2, 0x15, 0x4f, 0x16, 0xa6, 0x88, 0x3c
    };
    uint8_t chiffre[16];
    uint8_t dechiffre[16];

    printf("=== Test 1 : vecteur NIST (cle et texte nuls) ===\n");
    uint8_t zero_texte[16] = {0};
    uint8_t zero_cle[16] = {0};
    uint8_t zero_chiffre[16];
    uint8_t zero_attendu[16] = {
        0x66, 0xe9, 0x4b, 0xd4, 0xef, 0x8a, 0x2c, 0x3b,
        0x88, 0x4c, 0xfa, 0x59, 0xca, 0x34, 0x2b, 0x2e
    };
    aes128_encrypt(zero_texte, zero_cle, zero_chiffre);
    printf("Chiffre obtenu  : "); afficher_bloc(zero_chiffre);
    printf("Chiffre attendu : "); afficher_bloc(zero_attendu);
    if (comparer_blocs(zero_chiffre, zero_attendu)) {
        printf("-> CORRECT (conforme au standard NIST)\n\n");
    } else {
        printf("-> ECHEC\n\n");
    }

    printf("=== Test 2 : chiffrer puis dechiffrer ===\n");
    printf("Texte original : "); afficher_bloc(texte_original);

    aes128_encrypt(texte_original, cle, chiffre);
    printf("Chiffre        : "); afficher_bloc(chiffre);

    aes128_decrypt(chiffre, cle, dechiffre);
    printf("Dechiffre      : "); afficher_bloc(dechiffre);

    if (comparer_blocs(texte_original, dechiffre)) {
        printf("-> CORRECT : dechiffrer(chiffrer(x)) == x\n");
    } else {
        printf("-> ECHEC : le dechiffrement ne redonne pas le texte original\n");
    }

    return 0;
}