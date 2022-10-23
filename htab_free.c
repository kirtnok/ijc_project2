// htab_free.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdlib.h>
#include "htab_struc.h"
#include "htab.h"

void htab_free(htab_t * t){
    if(t!=NULL){
        //vycistenie dat
        htab_clear(t);
        //uvolnenie ukazatelov
        free(t->arr_ptr);
        free(t);
    }
}