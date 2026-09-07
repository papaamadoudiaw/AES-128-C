#include <stdio.h>
#include <stdint.h>
#include "aes.h"

void afficher_bloc(const uint8_t *bloc) {
    for (int i = 0; i < 16; i++) {
        printf("%02x ", bloc[i]);
    }
    printf("\n");
}

int main(void) {
    uint8_t texte_clair[16] = {0};
    uint8_t cle[16] = {0};
    uint8_t chiffre[16];

    uint8_t attendu[16] = {
        0x66, 0xe9, 0x4b, 0xd4, 0xef, 0x8a, 0x2c, 0x3b,
        0x88, 0x4c, 0xfa, 0x59, 0xca, 0x34, 0x2b, 0x2e
    };

    aes128_encrypt(texte_clair, cle, chiffre);

    printf("Chiffre obtenu  : "); afficher_bloc(chiffre);
    printf("Chiffre attendu : "); afficher_bloc(attendu);

    int correct = 1;
    for (int i = 0; i < 16; i++) {
        if (chiffre[i] != attendu[i]) {
            correct = 0;
        }
    }

    if (correct) {
        printf("RESULTAT : implementation CORRECTE (conforme au standard NIST)\n");
    } else {
        printf("RESULTAT : ECHEC, quelque chose ne va pas\n");
    }

    return 0;
}