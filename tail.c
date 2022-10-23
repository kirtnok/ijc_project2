// tail.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
//limit
#define MAX_LEN 4096

int main (int agrc, char **agrv){
    FILE *f = stdin;
    char *arg;
    long int val=10;
    int file_open = 0;
    //kontrola argumentov
    if (agrc > 4){
        return 1;
    }
    for(int i = 1; i<agrc; i++){
        // ak je -n dalsi argument musi byt nezaporne cislo
        if (strcmp(agrv[i], "-n")==0){
            val = strtol(agrv[i+1], &arg, 10);
            if(*arg !='\0'|| val <= 0){
                error_exit("tail.c: Wrong arguments");
            }
            i++;
        }
        //ak nie je -n alebo je -n a nejaky dalsi argument tak to to musi byt subor
        else{
            f =fopen(agrv[i], "r");
            file_open=1;
            if (f==NULL){
                error_exit("tail.c: Wrong arguments or file");
            }
        }

    }
    //alokacia bufferu
    char **buffer = malloc(val*sizeof(char *));
    if (buffer==NULL){
        if(file_open==1){
            fclose(f);
        }
        error_exit("tail.c: allocation error");
    }
    for (long int i = 0; i < val; i++){
        buffer[i] = calloc(MAX_LEN,sizeof(char)*MAX_LEN);
        if (buffer[i]==NULL){
            free(buffer);
            if(file_open==1){
                fclose(f);
            }
            error_exit("tail.c: allocation error");
        }
    }
    int count = 0;
    int c = 0;
    int lines_cut=0;
    //nacitanie celeho riadku
    while(fgets(buffer[count], MAX_LEN, f) != NULL) {
        //pokial nie je predposledny znak \n
        if(buffer[count][strlen(buffer[count])-1]!='\n'){     
            // ignorovanie ostatnych znakov ak prekrocil riadok limit
            while((c=fgetc(f)) != '\n'){
                if (c==EOF){
                    break;
                }
                continue;
            }
            if (c != EOF){
                //error pri ifgnorovani riadku
                if(lines_cut==0){
                    warning_msg("tail.c: Line longer than %d chars", MAX_LEN-1);
                    lines_cut=1;
                }
                //nahrada \n
                buffer[count][strlen(buffer[count])-1]='\n';
            }          


        }
        //pociatnie indexu v bufferi
        count++;
        if (count == val){
            count = 0;
        }
    }
    //spravne vytlacenie riadkov podla ulozeneho countu
    for (int i = count; i < val; i++){
        printf("%s", buffer[i]);
    }
    for (int i = 0; i<count;i++){
        printf("%s", buffer[i]);
    }
    // uvolnovanie
    for (long int i = 0; i < val; i++){
        if (buffer[i]!=NULL){
            free(buffer[i]);
        }
    }
    free(buffer);
    if(file_open==1){
        fclose(f);
    }
    return 0;
}
