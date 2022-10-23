// htab_clear.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdlib.h>
#include "htab_struc.h"
#include "htab.h"

void htab_clear(htab_t * t){
    struct htab_item *tmp_it;
    //loopovanie bucketmi
    for (size_t i = 0; i<t->arr_size;i++){
        //loopovanie itemami
        while(t->arr_ptr[i]!=NULL){
            //uvolnovanie postupne vsetkych hodnot
            tmp_it=t->arr_ptr[i]->next;
            free((char*)t->arr_ptr[i]->pair.key);
            free(t->arr_ptr[i]);
            t->arr_ptr[i]=tmp_it;
        }

    }
    t->size=0;
}