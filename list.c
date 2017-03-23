#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_create() {
	
	list_t *list = malloc(sizeof(list_t));
	if(!list){
		return NULL;
	}
	
	list->head = NULL;
		
	return list;
}

void list_destroy(list_t *list) {
	
	if(!list){
		return;
	}
	
	list_make_empty(list);
	free(list);
}

static node_t* new_node(data_t data) {

	node_t* node = (node_t*)malloc(sizeof(node_t));
	if(!node){
		return NULL;
	}
	
	node->data = data;
	node->next = NULL;

	return node;
}

node_t *list_append_tail(list_t *list, data_t data){

	node_t* new;

	if(!list){
		return NULL;
	}

	new = new_node(data); 
	if(!new){
		return NULL;
	}

	node_t *current = list->head;
	if(current){
		while(current->next != NULL){ 
			current = current->next;
		}
		current->next = new;
		new->next = NULL;
	} else {
		list->head = new;
		new->next = NULL;
	  }

	return new;
}

void list_remove(list_t *list, node_t *node) {
	
	node_t *current;

	if(!list || !node){
		return;
	}

	current = list->head;
	if(!current){
		return;
	} else if(current == node){
		list->head = current->next;
		free(node);
		return;
	  }

	while(current->next != node && current->next != NULL){
		current = current->next;
	}

	if(!current->next)
		return;

	current->next = node->next;
	free(node);
}

void list_remove_head(list_t *list) {

	if(!list){
		return;
	}

	list_remove(list, list->head);
}

void list_make_empty(list_t *list) {
	
	if(!list){
		return;
	}

	while(list->head){
		list_remove_head(list);
	}
}

unsigned int list_size(list_t *list){

	node_t *current = list->head;

	int size = 0;

	while(current != NULL){
		++size;
		current = current->next;
	}
	return size;
}

void insert_dictionary_words_to_trie(list_t *list, trie_tree* trie){

	if(!list || !trie){
		return;
	}

	node_t *current = list->head;

	while(current != NULL){
		trie_insert(trie, current->data.word);
		current = current->next;
	}
}

void print_words_frequency(list_t *list, trie_tree* trie){
	
	if(!list || !trie){
		return;
	}

	node_t *current = list->head;

	unsigned int size = list_size(list);
	unsigned int i = 0;

	while(current != NULL){
		if(i != size-1){
			printf("%d ", seen_times(trie, current->data.word));
			current = current->next;
		} else{
			printf("%d", seen_times(trie, current->data.word));
			current = current->next;
		}
		++i;
	}
	printf("\n");
}