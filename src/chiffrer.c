#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "aes.h"

#define TAILLE_BLOC 16

void afficher_bloc(const uint8_t *bloc) {
    for (int i = 0; i < 16; i++) {
        printf("%02x ", bloc[i]);
    }
    printf("\n");
}

void lire_bloc(const char *invite, uint8_t *bloc) {
    char buffer[100];

    printf("%s", invite);
    fgets(buffer, sizeof(buffer), stdin);

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--;
    }

    if (len > TAILLE_BLOC) {
        printf("Attention : entree tronquee a 16 caracteres.\n");
        len = TAILLE_BLOC;
    }

    for (int i = 0; i < TAILLE_BLOC; i++) {
        if (i < (int)len) {
            bloc[i] = (uint8_t)buffer[i];
        } else {
            bloc[i] = 0x00;
        }
    }
}
void lire_cle(const char *invite, uint8_t *bloc) {
    char buffer[100];

    printf("%s", invite);
    fgets(buffer, sizeof(buffer), stdin);

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
        len--;
    }

    if (len != TAILLE_BLOC) {
        printf("Attention : la cle devrait faire exactement 16 caracteres (actuellement %zu).\n", len);
        printf("Elle sera completee ou tronquee automatiquement.\n");
    }

    for (int i = 0; i < TAILLE_BLOC; i++) {
        if (i < (int)len) {
            bloc[i] = (uint8_t)buffer[i];
        } else {
            bloc[i] = 0x00;
        }
    }
}

int main(void) {
    uint8_t message[16];
    uint8_t cle[16];
    uint8_t chiffre[16];

    printf("=== Chiffrement AES-128 ===\n");
    lire_bloc("Message a chiffrer (16 caracteres max) : ", message);
    lire_cle("Cle (16 caracteres exactement)          : ", cle);

    aes128_encrypt(message, cle, chiffre);

    printf("\n--- Resultat ---\n");
    printf("Message (hex) : "); afficher_bloc(message);
    printf("Cle     (hex) : "); afficher_bloc(cle);
    printf("Chiffre (hex) : "); afficher_bloc(chiffre);

    return 0;
}