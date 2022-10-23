// htab_bucket_count.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdint.h>
#include "htab_struc.h"
#include "htab.h"

size_t htab_bucket_count(const htab_t * t){
    return t->arr_size;
}
