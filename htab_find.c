// htab_find.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdint.h>
#include <string.h>
#include "htab_struc.h"
#include "htab.h"
htab_pair_t * htab_find(htab_t * t, htab_key_t key) {
    unsigned index = (htab_hash_function(key) % t->arr_size);
    unsigned key_len = strlen(key);
    for (struct htab_item *item = t->arr_ptr[index]; item != NULL; item = item->next) {
        if ((key_len == strlen(item->pair.key)) && (!strcmp(item->pair.key, key))) {
            return &(item->pair);
        }
    }
    return NULL;
}
