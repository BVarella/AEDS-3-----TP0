#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

static int calc_index(char c){
	return ((int)c - (int)'a');
}

trie_tree* trie_create(){

	trie_tree* trie = malloc(sizeof(trie_tree));
	
	if(!trie){
		return NULL;
	}

	trie->root = new_trie_node();

	return trie;
}

trie_node* new_trie_node(){

	trie_node* node = (trie_node*) malloc(sizeof(trie_node));
	
	if(!node){
		return NULL;
	}

	int i;

	node->is_word = 0;
	node->num_visited = 0;

	for(i = 0; i < ALPHABET; ++i){
		node->next_char[i] = NULL;
	}

	return node;
}

void trie_insert(trie_tree* trie, char* key){

	int current_position;
	int char_index;
	int word_size = strlen(key);
	trie_node* pointer = trie->root;

	for(current_position = 0; current_position < word_size; ++current_position){
		char_index = calc_index(key[current_position]);
		if(pointer->next_char[char_index] == NULL){
			pointer->next_char[char_index] = new_trie_node();
		}
		pointer = pointer->next_char[char_index];
	}

	pointer->is_word = 1;
}

int trie_search(trie_tree* trie, char* key){

	int current_position;
	int char_index;
	int word_size = strlen(key);	
	trie_node* pointer = trie->root;

	for(current_position = 0; current_position < word_size; ++current_position){
		char_index = calc_index(key[current_position]);
		if(pointer->next_char[char_index] == NULL){
			return 0;
		}
		pointer = pointer->next_char[char_index];
	}

	if(pointer != NULL && pointer->is_word == 1){
		pointer->num_visited = pointer->num_visited + 1;
		return 1;
	}
	else return 0;
}

int seen_times(trie_tree* trie, char* key){
	
	int current_position;
	int char_index;
	int word_size = strlen(key);	
	trie_node* pointer = trie->root;

	for(current_position = 0; current_position < word_size; ++current_position){
		char_index = calc_index(key[current_position]);
		if(pointer->next_char[char_index] == NULL){
			return 0;
		}
		pointer = pointer->next_char[char_index];
	}

	return pointer->num_visited;
}

void free_all(trie_node* root){

	int i;

	for (i = 0; i < ALPHABET; ++i){
		if (root->next_char[i] != NULL){
			free_all(root->next_char[i]);
		}
	}

	free(root);
}

void trie_destroy(trie_tree* trie){

	free_all(trie->root);
	free(trie);
}