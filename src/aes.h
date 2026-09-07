#ifndef AES_H
#define AES_H

#include <stdint.h>

void sub_bytes(uint8_t *bloc);
void shift_rows(uint8_t *bloc);
void mix_columns(uint8_t *bloc);
void add_round_key(uint8_t *bloc, const uint8_t *round_key);
void key_expansion(const uint8_t *cle, uint8_t *round_keys);
void aes128_encrypt(const uint8_t *bloc_entree, const uint8_t *cle, uint8_t *bloc_sortie);
void inv_sub_bytes(uint8_t *bloc);
void inv_shift_rows(uint8_t *bloc);
void inv_mix_columns(uint8_t *bloc);
void aes128_decrypt(const uint8_t *bloc_entree, const uint8_t *cle, uint8_t *bloc_sortie);
#endif