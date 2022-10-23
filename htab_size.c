// htab_size.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdint.h>
#include "htab_struc.h"
#include "htab.h"

size_t htab_size(const htab_t * t){
    return t->size;
}