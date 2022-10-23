// wordcount.c
// Řešení IJC-DU2, 20.4.2022
// Autor: Jakub Kontrík, FIT
#include <stdio.h>

#include "htab.h"
#include "io.h"
#include "error.h"
/*nastavenie pociatocnej velkosti tabulky
* prvocislo kvoli znizeniu poctu konfliktov
* vacsia tabulka aby sa nemusela resizovat 
casto co sposobuje spomalovanie*/

#define HTAB_SIZE 4241
#define MAX_CHAR 128

//nova hash funkcia pomocou podmieneho prekladu
#ifdef HASHTEST
size_t htab_hash_function(const char *str) {
    uint32_t h=0;
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 87269*h + *p;
    return h;
}

#endif //HASHTEST
//printovanie hodnot z tabulky
void print_htab (htab_pair_t *data) {
    printf("%s\t%d\n", data->key, data->value);
}

int main() {
    htab_t *t=htab_init(HTAB_SIZE);
    //exit pokial chybna alokacia
    if(t==NULL){
        error_exit("wordcount.c: Wrong allocation");
    }
    char word_buf[MAX_CHAR];
    int word_len=0;
    // loopovanie slovami z stdin 
    while((word_len=read_word(word_buf,MAX_CHAR-1,stdin))!=EOF){
        // ulozenie slova do tabulky
        htab_pair_t *pair = htab_lookup_add(t, word_buf);
        if(pair==NULL){
            error_exit("wordcount.c: Wrong allocation");
        }
        //navysenie hodnoty v tabulke
        pair->value++;
        // vycistenie bufferu
        for(int i = 0; i<MAX_CHAR;i++){
            word_buf[i]='\0';
        }
    }
    //vystup
    htab_for_each(t, &print_htab);
    htab_free(t);

    return 0;
}