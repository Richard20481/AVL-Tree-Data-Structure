/**
 * AVL tree data structure library.
 */

/**
 * Header guards.
 */
#ifndef AVLTREE_LIB
#define AVLTREE_LIB

/**
 * 
 */
#include <stdint.h>
#include <malloc.h>

/**
 * Programmer defiend header files.
 */

/**
 * Library macros.
 */
#define AVLTREE_LIB_VERSION_2_0

/**
 * 
 */
#ifndef __cplusplus

/**
 * Macro magic...
 */
#pragma pack(2)

/**
 * The decluration for the avl node structure.
 */
struct avl_node{

    int64_t key;            //Nodes key value.
    int64_t h;              //The nodes height.

    struct avl_node* l_ptr; //The pointer to the left node.
    struct avl_node* r_ptr; //The poitner to the right node.
    void* d_ptr;            //The pointer to the data.
};

/**
 * The decluration for the avl data structure.
 */
typedef struct avl {

    struct avl_node* n_ptr; //The pointer to the root of the tree.

    size_t s;               //Size if the data stored in each node.
    size_t n;               //Number of nodes in the tree.
    size_t h;               //Height of the tree.

} AVL_Tree;

/**
 * 
 */
void AVL_print(struct avl_node* n_ptr);

/**
 * Creates the new AVL tree.
 */
int8_t AVL_ini(AVL_Tree* tree, const size_t size);

/**
 * Inserts a new node into the tree.
 */
int8_t AVL_insert(struct avl_node** n_pptr, int64_t key);



#endif

/**
 * 
 */
#ifdef __cplusplus


#endif
#endif