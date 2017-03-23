#ifndef LIST_H
#define LIST_H

#include "trie.h"

typedef struct data_t {
	char word[16];
} data_t;

typedef struct node_t {
	data_t data;
	struct node_t *next;
} node_t;

typedef struct list_t {
	node_t *head;
} list_t;

//INICIALIZA A LISTA
list_t *list_create();
//ENCERRA A LISTA
void list_destroy(list_t *list);
//INSERE ELEMENTO NO FINAL DA LISTA
node_t *list_append_tail(list_t *list, data_t data);
//REMOVE ELEMENTO ESPECIFICO DA LISTA
void list_remove(list_t *list, node_t *node);
//REMOVE A CABECA DA LISTA
void list_remove_head(list_t *list);
//FAZ A LISTA FICAR VAZIA
void list_make_empty(list_t *list);
//RETORNA O NUMERO DE ELEMENTOS NA LISTA
unsigned int list_size(list_t *list);
//INSERE AS PALAVRAS DA LISTA NA ARVORE TRIE
void insert_dictionary_words_to_trie(list_t *list, trie_tree* trie);
//IMPRIME A FREQUENCIA DAS PALAVRAS DE UMA LISTA EM UMA ARVORE TRIE
void print_words_frequency(list_t *list, trie_tree* trie);

#endif