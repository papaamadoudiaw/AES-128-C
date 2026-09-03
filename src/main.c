#include <stdio.h>
#include <stdint.h>

void xor_bloc(const uint8_t *a, const uint8_t *b, uint8_t *resultat) {
    for (int i = 0; i < 16; i++) {
        resultat[i] = a[i] ^ b[i];
    }
}

void afficher_bloc(const uint8_t *bloc) {
    for (int i = 0; i < 16; i++) {
        printf("%02x ", bloc[i]);
    }
    printf("\n");
}

int main(void) {
    uint8_t texte[16] = {
        0x32, 0x88, 0x31, 0xe0, 0x43, 0x5a, 0x31, 0x37,
        0xf6, 0x30, 0x98, 0x07, 0xa8, 0x8d, 0xa2, 0x34
    };
    uint8_t cle[16] = {
        0x2b, 0x28, 0xab, 0x09, 0x7e, 0xae, 0xf7, 0xcf,
        0x15, 0xd2, 0x15, 0x4f, 0x16, 0xa6, 0x88, 0x3c
    };
    uint8_t resultat[16];

    xor_bloc(texte, cle, resultat);

    printf("Texte  : "); afficher_bloc(texte);
    printf("Cle    : "); afficher_bloc(cle);
    printf("XOR    : "); afficher_bloc(resultat);

    // Preuve que XOR est reversible : refaire le XOR redonne le texte original
    uint8_t verif[16];
    xor_bloc(resultat, cle, verif);
    printf("Verif  : "); afficher_bloc(verif);

    return 0;
}