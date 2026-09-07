#ifndef AES_H
#define AES_H

#include <stdint.h>

void sub_bytes(uint8_t *bloc);
void shift_rows(uint8_t *bloc);
void mix_columns(uint8_t *bloc);
#endif