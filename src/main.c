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
    uint8_t bloc[16] = {
        0x32, 0x88, 0x31, 0xe0, 0x43, 0x5a, 0x31, 0x37,
        0xf6, 0x30, 0x98, 0x07, 0xa8, 0x8d, 0xa2, 0x34
    };
uint8_t cle[16] = {
        0x2b, 0x28, 0xab, 0x09, 0x7e, 0xae, 0xf7, 0xcf,
        0x15, 0xd2, 0x15, 0x4f, 0x16, 0xa6, 0x88, 0x3c
    };
     uint8_t round_keys[176];
    key_expansion(cle, round_keys);
    printf("Les 11 sous-cles generees :\n");
    for (int tour = 0; tour < 11; tour++) {
        printf("Tour %2d : ", tour);
        afficher_bloc(round_keys + tour * 16);
    }
    printf("Avant SubBytes : "); afficher_bloc(bloc);

    sub_bytes(bloc);

    printf("Apres SubBytes : "); afficher_bloc(bloc);
    shift_rows(bloc);
    printf("Apres ShiftRows : "); afficher_bloc(bloc);
    mix_columns(bloc);
    printf("Apres MixColumns: "); afficher_bloc(bloc);
    add_round_key(bloc, cle);
    printf("Apres AddRoundKey: "); afficher_bloc(bloc);

    return 0;
}