#ifndef AES_H
#define AES_H

#include <stdint.h>

void sub_bytes(uint8_t *bloc);
void shift_rows(uint8_t *bloc);
void mix_columns(uint8_t *bloc);
void add_round_key(uint8_t *bloc, const uint8_t *round_key);
#endif