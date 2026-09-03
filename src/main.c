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

    printf("Avant SubBytes : "); afficher_bloc(bloc);

    sub_bytes(bloc);

    printf("Apres SubBytes : "); afficher_bloc(bloc);
    shift_rows(bloc);
    printf("Apres ShiftRows : "); afficher_bloc(bloc);

    return 0;
}