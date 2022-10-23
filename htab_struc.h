// htab_struct.h
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#ifndef __HTAB_STRUC_H__
#define __HTAB_STRUC_H__
#include <stdint.h>
#include "htab.h"
struct htab_item{
    htab_pair_t pair;
    struct htab_item *next;
};
struct htab{
    size_t size;
    size_t arr_size;
    struct htab_item **arr_ptr;
};


#endif // __HTAB_STRUC_H__