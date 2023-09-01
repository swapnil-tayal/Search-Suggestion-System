#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <string.h>
#include "trie.h"
#define NUM_CHAR 26


int main(){


    printf("Enter Word List :");

    int productsSize;
    scanf("%d", &productsSize);
    
    char **products = (char **)malloc(productsSize * sizeof(char *));

    for (int i = 0; i < productsSize; i++) {
        char buffer[100];
        scanf("%s", buffer);
        products[i] = (char *)malloc(strlen(buffer) + 1);
        strcpy(products[i], buffer);
    }
    
    char searchWord[100];
    printf("Enter the Seach Word ");
    scanf("%s", searchWord);

    Trie *root = createTrie();
    for(int i=0;i<productsSize;i++) {
        insert(root, products[i]);
    }

    int search_len = strlen(searchWord);
    char str[20];
    int k = 0;
    for(int i=0; i<20; i++) str[i] = '\0';

    for(int i=0;i<search_len;i++) {
        str[k++] = searchWord[i];
        printf("Words with prefix %s\n", str);
        suggestion(root, searchWord, 0, i);
        printf("\n");
    }
}
