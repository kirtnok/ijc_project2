// htab_for_each.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdint.h>
#include "htab_struc.h"
#include "htab.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    //loopovanie prvkami
    for (size_t i = 0; i<t->arr_size;i++){
        struct htab_item *j=t->arr_ptr[i];
        while(j!=NULL){
            //aplikacia funkcie na par
            f(&(j->pair));
            j=j->next;
        }
    }
}
