#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <string.h>
#define NUM_CHAR 26


typedef struct Trie{

    struct Trie *links[NUM_CHAR];
    bool isEnd;
    char *text;

} Trie;

Trie* createTrie() {
    
    Trie *node = (Trie *)malloc(sizeof(Trie));
    for(int i=0;i<NUM_CHAR;i++) {
        node->links[i] = NULL;
    }
    node->isEnd = false;
    node->text = NULL;

    return node;
}

void insert(Trie *node, char *word) {
    
    int length = strlen(word);
    Trie *temp = node;

    for(int i=0;i<length;i++) {

        int letter = word[i]-'a';

        if(temp->links[letter] == NULL) {
            temp->links[letter] = createTrie();
        }
        temp = temp->links[letter];
    }

    if(temp->isEnd) return;
    
    temp->isEnd = true;
    temp->text = word;
}

void suggestion(Trie *node, char *searchword, int k, int n) {
    
    if(node->isEnd){
        printf("%s\n", node->text);
    }

    for(int i=0;i<NUM_CHAR;i++){

        if(node->links[i] != NULL){

            int prefixChar = (searchword[k]-'a');
            if(k > n || prefixChar == i) {
                suggestion(node->links[i], searchword, k+1, n);
            }
        }
    }
}
