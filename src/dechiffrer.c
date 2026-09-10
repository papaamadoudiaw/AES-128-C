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

int valeur_chiffre(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    return -1;
}

void hex_vers_bloc(const char *hex_texte, uint8_t *bloc) {
    int octet_index = 0;
    int i = 0;

    while (hex_texte[i] != '\0' && octet_index < TAILLE_BLOC) {
        if (hex_texte[i] == ' ') {
            i++;
            continue;
        }

        int v1 = valeur_chiffre(hex_texte[i]);
        int v2 = valeur_chiffre(hex_texte[i + 1]);

        bloc[octet_index] = (uint8_t)((v1 << 4) | v2);
        octet_index++;
        i += 2;
    }
}

void lire_bloc_hex(const char *invite, uint8_t *bloc) {
    char buffer[100];

    printf("%s", invite);
    fgets(buffer, sizeof(buffer), stdin);

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    hex_vers_bloc(buffer, bloc);
}

int main(void) {
    uint8_t chiffre[16];
    uint8_t cle[16];
    uint8_t dechiffre[16];

    printf("=== Dechiffrement AES-128 ===\n");
    lire_bloc_hex("Chiffré en hexadecimal : ", chiffre);
    lire_bloc("Cle (16 caracteres exactement)             : ", cle);

    aes128_decrypt(chiffre, cle, dechiffre);

    printf("\n--- Resultat ---\n");
    printf("Chiffre   (hex) : "); afficher_bloc(chiffre);
    printf("Cle       (hex) : "); afficher_bloc(cle);
    printf("Dechiffre (hex) : "); afficher_bloc(dechiffre);
    printf("Dechiffre (txt) : %s\n", dechiffre);

    return 0;
}