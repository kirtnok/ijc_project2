// htab_hashZzz_function.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdint.h>
#include "htab_struc.h"
#include "htab.h"
size_t htab_hash_function(const char *str) {
    uint32_t h=0;     // musí mít 32 bitů
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}