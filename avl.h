/**
 * Author: Richard.G
 * AVL tree data structure library.
 */

/**
 * 
 */
#ifndef AVLTREE_LIB
#define AVLTREE_LIB

/**
 * 
 */
#include <stdint.h>
#include <malloc.h>

/**
 * 
 */

/**
 * Programmer defiend header files.
 */

/**
 * Library macros.
 */
// #define AVLTREE_LIB_VERSION_1_0

/**
 * 
 */
#ifndef __cplusplus

/**
 * Decluration for the avl tree data structure.
 */
#pragma pack(2)

typedef struct avl {

    struct node* n_ptr;

    size_t s;   //Size if the data.
    size_t n;   //Number of nodes.

} AVL_Tree;

/**
 * 
 */
void AVL_print(AVL_Tree* tree);

/**
 * Inserts a new node into the tree.
 */
int8_t AVL_insert(AVL_Tree* tree, int64_t key, void* d_ptr);

/**
 * Look for the data in the tree.
 */
void* AVL_find(AVL_Tree* tree_ptr, int64_t key);

/**
 * Look for the data in the tree.
 */
int8_t AVL_contains(AVL_Tree* tree_ptr, const int64_t key);

/**
 * Merges two avl trees together into one tree.
 */
int8_t AVL_merge(void);

/**
 * Splits a avl tree into two smaller trees.
 */
int8_t AVL_split(void);

/**
 * (API Abstraction interface...)
 */
int8_t AVL_remove(AVL_Tree tree, void* d_ptr);

#endif

/**
 * 
 */
#ifdef __cplusplus


#endif
#endif