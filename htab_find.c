// htab_find.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdint.h>
#include <string.h>
#include "htab_struc.h"
#include "htab.h"

htab_pair_t * htab_find(htab_t * t, htab_key_t key){
    //loopovanie prvkami
    for(size_t i = 0; i<t->arr_size; i++){
        struct htab_item *j=t->arr_ptr[i];
        while(j!=NULL){
            //porovnanie stringov
            if(strcmp(j->pair.key, key)==0){
                return &(j->pair);
            }
            j=j->next;
        }
    }
    return NULL;
}
