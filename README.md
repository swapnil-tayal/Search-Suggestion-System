# Trie-Based Search Suggestion System (C)

## Overview

This is a simple search suggestion system implemented in C using the Trie data structure. It provides an efficient way to suggest search terms based on user input, making it suitable for various applications such as search engines or autocomplete features.

### Features

- Efficient Trie data structure for storing search terms.
- Support for suggesting search terms based on user input.
- Minimal memory usage.

## Getting Started

These instructions will help you set up and use the search suggestion system in your C project.

### Prerequisites

- [C Compiler](https://gcc.gnu.org/) - Make sure you have a C compiler installed.

### Building the Project


  ```
   git clone https://github.com/swapnil-tayal/Search-Suggestion-System
  ```

### Usage

  ```
  #include "trie.c"
  ```

  ```
  Trie *root = createTrie();
  insert(root, products[i]);
  suggestion(root, searchWord, 0, wordLen);
  ```
   
