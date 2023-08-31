#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <string.h>
#define NUM_CHAR 26



typedef struct _trie_node_t {
    struct _trie_node_t *next[NUM_CHAR];
    bool terminated;
    char *text;
} trie_node_t;

trie_node_t *generate_tree_node(void) {
    trie_node_t *node = (trie_node_t *)malloc(sizeof(trie_node_t));
    for(int i=0;i<NUM_CHAR;i++) {
        node->next[i] = NULL;
    }
    node->terminated = false;
    node->text = NULL;

    return node;
}

bool insert_trie_node(trie_node_t **node, char *word) {
    if(*node == NULL) {
        *node = generate_tree_node();
    }

    int length = strlen(word);
    trie_node_t *temp = *node;
    for(int i=0;i<length;i++) {
        if(temp->next[(int)(word[i]-'a')] == NULL) {
            temp->next[(int)(word[i]-'a')] = generate_tree_node();
        }
        temp = temp->next[(int)(word[i]-'a')];
    }

    if(temp->terminated){

        return false;
    }
    temp->terminated = true;
    temp->text = word;
    return true;

}

void help(trie_node_t *node, char *searchword, int i_search, int n_search) {
    if(node->terminated) {
            printf("%s ", node->text);
    }

    for(int i=0;i<NUM_CHAR;i++) {
        if(node->next[i] != NULL) {
            if(i_search >= n_search || (int)(searchword[i_search]-'a') == i) {
                help(node->next[i], searchword, i_search+1, n_search);
            }

        }
    }
}


int main(){


    int productsSize;
    scanf("%d", &productsSize);
    
    char **products = (char **)malloc(productsSize * sizeof(char *));
    // printf("Enter the product names:\n");
    for (int i = 0; i < productsSize; i++) {
        char buffer[100];
        scanf("%s", buffer);
        products[i] = (char *)malloc(strlen(buffer) + 1); // +1 for null terminator
        strcpy(products[i], buffer);
    }
    
    char searchWord[100];
    // printf("Enter the search word: ");
    scanf("%s", searchWord);


    trie_node_t *root = NULL;
    for(int i=0;i<productsSize;i++) {
        insert_trie_node(&root, products[i]);
    }

    int search_len = strlen(searchWord);
    char str[20];
    int k = 0;
    for(int i=0; i<20; i++) str[i] = '\0';

    for(int i=0;i<search_len;i++) {
        str[k++] = searchWord[i];
        printf("%s- ", str);
        help(root, searchWord, 0, i+1);
        printf("\n");
    }
}
