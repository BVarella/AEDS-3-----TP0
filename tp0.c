#include "myfunctions.h"

int main(){

	list_t *dictionary_list = list_create();
	trie_tree* trie = trie_create();
	
	read_dictionary_words_from_stdin(dictionary_list);

	insert_dictionary_words_to_trie(dictionary_list, trie);

	write_word_occurrencies_to_dictionary(trie);

	print_words_frequency(dictionary_list, trie);

	list_destroy(dictionary_list);
	trie_destroy(trie);

	return 0;
}