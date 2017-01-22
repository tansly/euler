#ifndef TREE_H
#define TREE_H
#include <stddef.h>

typedef struct Treenode *Treeptr;

/*  function to free data stored in the nodes
 *  optionally supplied by the user of the tree, if the data is dynamically allocated
 *  called for the data pointers in each node */
typedef void (*Freefunction)(void *);

/*  function to compare the data in the nodes
 *  returns negative if the first arg is less than the second
 *  0 if they are equal
 *  positive if the first is greater than the second */
typedef int (*Cmpfunction)(const void *, const void *);

typedef struct Tree_meta {
    Treeptr root;
    size_t data_size; /*  size of the data to be stored */
    Cmpfunction cmpfunc; /*  function to compare data */
    Freefunction freefunc; /*  function to free data (optional) */
} Tree_meta;

typedef struct Treenode {
    Tree_meta *metadata;
    void *data;
    long count;
    Treeptr left;
    Treeptr right;
} Treenode;

 

/*  make a new tree given its data size, comparison function, [freeing function] (optional) */
Treeptr mktree(size_t data_size, Cmpfunction cmpfnc, Freefunction freefunc);

int is_empty(Treeptr tree);

int is_leaf(Treeptr tree);

void insert(Treeptr tree, const void *new_data);

long tree_get_count(Treeptr tree, const void *data);

void *tree_get_highest_val(Treeptr tree);

void tree_destroy(Treeptr tree);

int tree_height(Treeptr tree);

void *tree_get_data(Treeptr tree, const void *key);

#endif
