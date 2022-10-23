// htab_erase.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdlib.h>
#include <stdint.h>
#include "htab_struc.h"
#include "htab.h"
/*minimum urcene ako pomer poctu poloziek a velkosti ked pomer 
size/arr_size bude mensi ako 0.25 tabulka sa zmensi
zbytocne velka tabulka zabera vela miesta a mala tabulka je pomala
*/
#define AVG_LEN_MIN 0.25
bool htab_erase(htab_t * t, htab_key_t key){
    struct htab_item *j;
    struct htab_item *before;
    //loopovanie bucketmi
    for (size_t i = 0; i<t->arr_size;i++){
        j=t->arr_ptr[i];
        before = NULL;
        //loopovanie polozkami
        while(j!=NULL){
            if(strcmp(j->pair.key,key)==0){
                struct htab_item *tmp=j->next;
                if(before==NULL){
                    t->arr_ptr[i]=tmp;

                }
                else{
                    before->next=tmp;
                }
                //odstranenie polozky a jej dat
                free((char*)j->pair.key);
                free(j);
                t->size--;
                //zmensenie tabulky
                if((float)t->size/t->arr_size<AVG_LEN_MIN){
                    htab_resize(t,t->arr_size/2);
                }
                return true;
            }
            before=j;
            j=j->next;
        }
    }
    return false;
}