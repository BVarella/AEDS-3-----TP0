#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "trie.h"

//SALVA PALAVRAS DO DICIONARIO EM UMA LISTA
void read_dictionary_words_from_stdin(list_t* dictionary_list);
//CONTA O NUMERO DE VEZES QUE CADA PALAVRA DO DICIONARIO APARECE NO TEXTO
void write_word_occurrencies_to_dictionary(trie_tree* trie);

#endif