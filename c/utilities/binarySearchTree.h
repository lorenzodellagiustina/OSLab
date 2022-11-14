#ifndef _BST_H_
#define _BST_H_
#include <stdio.h>
#include "list.h"

struct Tnode {
    int key;
    struct Tnode *lt;
    struct Tnode *rt;
};

/**
 * Initialize a BST by creating its root
 * @param key the key/index/int of the root
 * @return a pointer to the root of the BST
 */
struct Tnode *create(int key);

/**
 * Insert an int in a BST
 * @param key the int to be added
 * @param root the address of the BST's root node
 */
void insert(int key, struct Tnode *root);

/**
 * Find a key in the BST
 * @param key the int to be found
 * @param root the address of the BST's root node
 * @return an int representing a bool (0 > false; 1 > true)
 */
int find(int key, struct Tnode *root);

/**
 * Remove the pointed BST from memory
 * @param root the address of the BST's root node
 */
void destroy(struct Tnode *root);

/**
 * Return a pointer to the list representing the BST
 * @param root the address of the BST's root node
 * @return a pointer to the first node of the list
 */
struct Lnode *to_list(struct Tnode *root);

#endif