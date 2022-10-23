// htab_init.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdlib.h>
#include "htab_struc.h"
#include "htab.h"

htab_t *htab_init(size_t n){
    htab_t *htab;
    //alokacia a nasledna kontrola
    htab=malloc(sizeof(htab_t));
    if(htab==NULL){
        return NULL;
    }
    //inicializacia struktury
    htab->arr_size=n;
    htab->size=0;
    // alokacia ukazatelov a kontrola
    htab->arr_ptr=malloc(sizeof(struct htab_item*)*n);
    if(htab->arr_ptr==NULL){
        free(htab);
        return NULL;
    }
    //inicializacia
    for(size_t i=0; i<n;i++){
        htab->arr_ptr[i]=NULL;

    }
    return htab;
}
