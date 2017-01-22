#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  make a new tree given its data size, comparison function, [freeing function] (optional) */
Treeptr mktree(size_t data_size, Cmpfunction cmpfunc, Freefunction freefunc)
{
    Treeptr new_tree;
    new_tree = calloc(1, sizeof(Treenode)); /*  allocate storage for the node */
    new_tree -> metadata = calloc(1, sizeof(Tree_meta)); /*  allocate storage for the metadata */
    new_tree -> metadata -> root = new_tree;
    new_tree -> metadata -> data_size = data_size;
    new_tree -> metadata -> cmpfunc = cmpfunc;
    new_tree -> metadata -> freefunc = freefunc;
    return new_tree;
}

static size_t get_data_size(Treeptr tree)
{
    return tree -> metadata -> data_size;
}

static Cmpfunction get_cmpfunc(Treeptr tree)
{
    return tree -> metadata -> cmpfunc;
}

static Freefunction get_freefunc(Treeptr tree)
{
    return tree -> metadata -> freefunc;
}

/*  create a node for an existing tree (ready for insertion with new data), metadata set */
static Treeptr mknode(Treeptr ex_tree, const void *new_data)
{
    Treeptr new_node;
    new_node = calloc(1, sizeof(Treenode));
    new_node -> data = calloc(1, get_data_size(ex_tree));
    new_node -> count = 1;
    new_node -> metadata = ex_tree -> metadata;
    memcpy(new_node -> data, new_data, get_data_size(ex_tree));
    return new_node;
}

int is_empty(Treeptr tree)
{
    return tree == NULL;
}

int is_leaf(Treeptr tree)
{
    return !is_empty(tree) && is_empty(tree -> left) && is_empty(tree -> right);
}

/*  inserting the first element (special case) */
static void insert_at_root(Treeptr tree, const void *new_data)
{
    tree -> data = calloc(1, get_data_size(tree));
    memcpy(tree -> data, new_data, get_data_size(tree));
    tree -> count = 1;
}

static Treeptr _insert(Treeptr tree, const void *new_data, Treeptr root)
{
    if (is_empty(tree)) {
        return mknode(root, new_data);
    } else if ((*get_cmpfunc(root))(new_data, tree -> data) < 0) {
        tree -> left = _insert(tree -> left, new_data, root);
        return tree;
    } else if ((*get_cmpfunc(root))(new_data, tree -> data) == 0) {
        tree -> count++;
        return tree;
    } else {
        tree -> right = _insert(tree -> right, new_data, root);
        return tree;
    }
}

void insert(Treeptr tree, const void *new_data)
{
    if (is_empty(tree)) {
        fputs("insert(): tree not initialized\n", stderr);
        exit(1);
    }
    else if (tree -> data == NULL) {
        /* special case -> insert to a new tree (at root) */
        insert_at_root(tree, new_data);
    } else {
        _insert(tree, new_data, tree);
    }
}

/*  get the count of a data item, 0 if not found */
long tree_get_count(Treeptr tree, const void *data)
{
    if (is_empty(tree)) {
        return 0;
    } else if ((*get_cmpfunc(tree))(data, tree -> data) < 0) {
        return tree_get_count(tree -> left, data);
    } else if ((*get_cmpfunc(tree))(data, tree -> data) == 0) {
        return tree -> count;
    } else {
        return tree_get_count(tree -> right, data);
    }
}

/*  find the highest value data, and return it (allocates new storage for returned data, free() it when done */
void *tree_get_highest_val(Treeptr tree)
{
    if (is_empty(tree)) {
        /*  SHOULD NOT HAPPEN */
        fputs("tree_get_highest_val(): ERROR (empty tree)\n", stderr);
        return NULL;
    } else if (is_empty(tree -> right)) {
        /*  if right child is empty there are no greater values */
        void *data = malloc(get_data_size(tree));
        memcpy(data, tree -> data, get_data_size(tree));
        return data;
    } else {
        return tree_get_highest_val(tree -> right);
    }
}

static void _tree_destroy(Treeptr tree)
{
    if (is_empty(tree)) {
        return;
    } else {
        _tree_destroy(tree -> left);
        _tree_destroy(tree -> right);
        if (get_freefunc(tree) != NULL) {
            (*get_freefunc(tree))(tree -> data);
        }
        free(tree -> data);
        free(tree);
    }
}

void tree_destroy(Treeptr tree)
{
    Tree_meta *meta = tree -> metadata;
    _tree_destroy(tree);
    free(meta);
}

int tree_height(Treeptr tree)
{
    if (is_empty(tree)) {
        return -1; /*  depth of a NULL node */
    } else {
        int h_l, h_r;
        h_l = 1 + tree_height(tree -> left);
        h_r = 1 + tree_height(tree -> right);
        return (h_l > h_r) ? h_l : h_r;
    }
}

/*  search data by key object, return the matching data in a new allocated space, NULL if not found */
void *tree_get_data(Treeptr tree, const void *key)
{
    if (is_empty(tree)) {
        return NULL;
    } else if ((*get_cmpfunc(tree))(key, tree -> data) < 0) {
        return tree_get_data(tree -> left, key);
    } else if ((*get_cmpfunc(tree))(key, tree -> data) > 0) {
        return tree_get_data(tree -> right, key);
    } else {
        void *found;
        found = malloc(get_data_size(tree));
        memcpy(found, tree -> data, get_data_size(tree));
        return found;
    }

}

/*  searches by key, removes the node found from the tree, returns the data stored */
#if 0
void *tree_pop_node(Treeptr tree, const void *key)
{
    if (is_empty(tree)) {
        return NULL;
    } else if ((*get_cmpfunc(tree))(key, tree -> data) < 0) {
        return tree_pop_node(tree -> left, key);
    } else if ((*get_cmpfunc(tree))(key, tree -> data) > 0) {
        return tree_pop_node(tree -> right, key);
    } else {
        /*  TODO: do more reading, a little bit complicated */
    }
}
#endif
