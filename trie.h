#ifndef MYTRIE_H
#define MYTRIE_H

#define ALPHABET 26

typedef struct trie_node{
	
	struct trie_node* next_char[ALPHABET];
	int is_word;
	int num_visited;

} trie_node;

typedef struct trie_tree{

	trie_node* root;

} trie_tree;

//INICIALIZA A ARVORE
trie_tree* trie_create();
//CRIA NOVO NODO
trie_node* new_trie_node();
//INSERE PALAVRA NA ARVORE
void trie_insert(trie_tree* trie, char* key);
//PROCURA PALAVRA NA ARVORE
int trie_search(trie_tree* trie, char* key);
//RETORNA O NUMERO DE VEZES QUE UMA PALAVRA FOI PESQUISADA
int seen_times(trie_tree* trie, char* key);
//ENCERRA A ARVORE
void free_all(trie_node* root);
//ENCERRA A ARVORE (CHAMAR APOS free_all)
void trie_destroy(trie_tree* trie);

#endif