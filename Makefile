CC = gcc

tp0: tp0.c list.c trie.c myfunctions.c
	$(CC) -Ofast tp0.c list.c trie.c myfunctions.c -o tp0 -lm