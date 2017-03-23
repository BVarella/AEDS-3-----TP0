#include "myfunctions.h"

void read_dictionary_words_from_stdin(list_t* dictionary_list){

	int N, i;
	char temp_word[16];
	data_t temp_word_to_list;

	if(scanf("%d\n", &N) != 1){
		return;
	}

	for(i = 0; i < N; ++i){
		if(scanf("%s", temp_word) != 1){
			return;
		}
		strcpy(temp_word_to_list.word, temp_word);
		list_append_tail(dictionary_list, temp_word_to_list);
	}
}

void write_word_occurrencies_to_dictionary(trie_tree* trie){

	if(!trie){
		return;	
	}
	
	int M, i;
	char temp_word[16];
	
	if(scanf("%d\n", &M) != 1){
		return;
	}

	for(i = 0; i < M; ++i){
		if(scanf("%s", temp_word) != 1){
			return;
		}
		trie_search(trie, temp_word);
	}
}