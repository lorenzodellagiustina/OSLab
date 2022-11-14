#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binarySearchTree.h"
#include "list.h"

struct Tnode *create(int key) {
    struct Tnode *ptr = malloc(sizeof(struct Tnode));
    ptr->key = key;
    ptr->lt = NULL;
    ptr->rt = NULL;
}

void insert(int key, struct Tnode *root) {
    if (*root) {
        if (key <= root->key) {
            insert(key, root->lt);
        } else { // key > root->key
            assert(key > root->key);
            insert(key, root->rt);
        }
    } else {
        root = create(key);
    }
}

int find(int key, struct Tnode *root) {
    if(*root) {
        if (root->key == key) {
            return 1;
        } else if (key < root->key) {
            return find(key, root->lt);
        } else {
            assert(key > root->key);
            return find(key, root->rt);
        }
    } else {
        return 0;
    }
}

void destroy(struct Tnode *root) {
    destroy(root->lt);
    destroy(root->rt);
    free(root);
}

truct Lnode *to_list(struct Tnode *root) {

}