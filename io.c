// io.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "io.h"
#include "error.h"

#define MAX_LEN 127

int read_word(char *s, int max, FILE *f){
    int c,i=0;
    int words_cut=0;
    // kontrola limitu
    if(max>MAX_LEN){
        max=MAX_LEN;
    }
    //vynechanie vsetkych charov na zaciatku
    while(isspace(c=fgetc(f)));
    if(c==EOF){
        return EOF;
    }
    //nacitavanie dat
    while(i<max && c != EOF){
        if(isspace(c)){
            break;
        }
        else{
            s[i]=c;
            i++;
        }
        c=fgetc(f);
    }
    // upozornenie nadlhsie slov a ignorovanie ostatku
    if(i==max){
        if(words_cut==0){
            warning_msg("io.c: Word longer than %d chars", MAX_LEN);
            words_cut=1;
        }
        while(!(isspace(c))){
            c=fgetc(f);
        }
    }
    //ukoncenie slova \0
    s[i]='\0';
    return strlen(s);
}
