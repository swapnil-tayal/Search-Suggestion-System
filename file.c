#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <string.h>
#include "trie.h"
#define NUM_CHAR 26


int main(){

    printf("Enter Word List : ");

    // product list size
    int productsSize;
    scanf("%d", &productsSize);
    
    char **products = (char **)malloc(productsSize * sizeof(char *));

    // input words
    for (int i = 0; i < productsSize; i++) {
        char buffer[100];
        scanf("%s", buffer);
        products[i] = (char *)malloc(strlen(buffer) + 1);
        strcpy(products[i], buffer);
    }
    
    // search word
    char searchWord[100];
    printf("Enter the Seach Word : ");
    scanf("%s", searchWord);
    printf("\n");

    // intializaing trie 
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

        // GUI 
        for(int j=0; j<40; j++) printf("-");
        printf("\n");
        printf("|");
        int spaces = (38 - (k+7) + 1)/2;
        for(int j=0; j<spaces; j++) printf(" ");
        printf("Prefix %s", str);
        for(int j=0; j< 38-(spaces+7+k); j++) printf(" ");
        printf("|\n");
        for(int j=0; j<40; j++) printf("-");
        printf("\n");

        // suggestion call 
        suggestion(root, searchWord, 0, i);
        
        // GUI
        for(int j=0; j<40; j++) printf("-");
        printf("\n\n");
    }
}
