// htab_resize.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdlib.h>
#include <stdint.h>
#include "htab_struc.h"
#include "htab.h"
// minimalna velkost tabulky
#define MIN_SIZE 3
void htab_resize(htab_t *t, size_t newn){
    struct htab_item **new_ptr;
    //ak je mensia velkost nastavi sa minimallna
    if(newn<MIN_SIZE){
        newn=MIN_SIZE;
    }
    //novy ukazatel 
    new_ptr=malloc(sizeof(struct htab_item*)*newn);
    if(new_ptr==NULL){
        return;
    }
    //inicializovanie
    for(size_t i=0; i<newn;i++){
        new_ptr[i]=NULL;

    }
    struct htab_item *before;
    //prechod starou tabulkou
    for (size_t i = 0; i<t->arr_size;i++){
        struct htab_item *j=t->arr_ptr[i];
        while(j!=NULL){
            //vypocet noveho indexu
            size_t index=htab_hash_function(j->pair.key)%newn;
            //hladanie miesta na ulozenie v novom ukazateli
            if(new_ptr[index]==NULL){
                new_ptr[index]=j;
            }
            else{
                //najdenie konca
                struct htab_item *k=new_ptr[index];
                while(k->next!=NULL){
                    k=k->next;
                }
                k->next=j;
            }
            //posun ukazatelov
            before = j;
            j=j->next;
            before->next = NULL;
        }
        
    }
    //ovolnenie stareho ukazatela a nastavenie noveho
    free(t->arr_ptr);
    t->arr_ptr=new_ptr;
    t->arr_size=newn;
}