// wordcount.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdlib.h>
#include <stdint.h>
#include "htab_struc.h"
#include "htab.h"
/*nastavenie tzv loadfactoru urcuje kedy sa ma tabulka
zvacsit pre najvyssiu efektivicu pracovania s nou ak je 
pomer size/arr_ptr zvacsi sa*/

#define AVG_LEN_MAX 0.70

htab_pair_t *htab_lookup_add(htab_t * t, htab_key_t key){
    //ak nenajde dany prvok prida sa
    if (htab_find(t, key)!=NULL){
        return htab_find(t, key);
    }
    //vypocet indexu pomocou hash funckie
    size_t index= htab_hash_function(key) % t->arr_size;
    //alokovanie v pamati pre novy item
    struct htab_item *newit= malloc(sizeof(struct htab_item));
    if(newit==NULL){
        return NULL;
    }
    //inicializacia itemu
    newit->next=NULL;
    newit->pair.key=malloc(strlen(key)+1);
    strcpy((char*)newit->pair.key,key);
    newit->pair.value=0;
    //pridanie itemu na dany index
    if(t->arr_ptr[index]==NULL){
        t->arr_ptr[index]=newit;
    }
    else{
        struct htab_item *i = t->arr_ptr[index];
        while (i->next!=NULL){
            i=i->next;
        }
        i->next=newit;
    }
    t->size++;
    //zvacenie tabulky ak je potreba pre zavhovanie efektivity
    if((float)t->size/t->arr_size>AVG_LEN_MAX){
        htab_resize(t,t->arr_size*2);

    }
    return &(newit->pair);
}