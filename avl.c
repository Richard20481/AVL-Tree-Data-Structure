/**
 * AVL tree data structure library.
 */

//80 line limit!!!
////////////////////////////////////////////////////////////////

/**
 * C standard library header files.
 */
#include <stdio.h>
#include <stdint.h> 

/**
 * Programmer defiend header files.
 */
#include "../Headers/avl.h"

/**
 * 
 */
#define AVL_NODESIZE (sizeof(struct avl_node))

/**
 * If using the C implomentation,
 * compile the following block.
 */
#ifndef __cplusplus

/**
 * Error macros. 
 */
#define INVALIDPERAMITER -1
#define FAILEDTOALLOCATE -2

/**
 * Prints the AVL tree to the termianl in middle,
 * left,right(MLR) form.
 */
void AVL_print(struct avl_node* n_ptr){

    if(n_ptr){

        printf("\n(%ld)::::(h= %ld)", n_ptr->key, n_ptr->h);
        AVL_print(n_ptr->l_ptr);
        AVL_print(n_ptr->r_ptr);
    }
}

/**
 * Creates the new AVL tree.
 */
int8_t AVL_ini(AVL_Tree* tree, const size_t size){

    /**
     * Peramiter validation.
     */
    if(!tree) return INVALIDPERAMITER;
    if(tree->n_ptr) return INVALIDPERAMITER;
    if(!size) return INVALIDPERAMITER;

    /**
     * Sets the tree's attributes to default values. 
     */
    tree->h = 0;
    tree->n = 0;
    tree->s = size;

    tree->n_ptr = NULL;
    return 0;
}

/**
 * Creates a new node with a key.
 */
int8_t AVL_node_ini(struct avl_node** n_pptr, int64_t key){

    /**
     * Peramiter validation.
     */
    if(*n_pptr) return INVALIDPERAMITER;
    if(key < 0) return INVALIDPERAMITER;

    /**
     * Allocates memeory for the new node.
     */
    *n_pptr = (struct avl_node*)malloc(AVL_NODESIZE);
    if(!*n_pptr) return FAILEDTOALLOCATE;

    /**
     * Sets the nodes attributes.
     */
    (*n_pptr)->key = key;
    (*n_pptr)->h = 0x01;
    return 0;
}

/**
 * Right rotation.
 */
void* AVL_rr(struct avl_node* n_ptr){

    /**
     * 
     */
    struct avl_node* t_ptr = NULL;

    /**
     * Peramiter validation.
     */
    if(!n_ptr) return NULL;
    if(!n_ptr->l_ptr) return NULL;

    /**
     * Changes pointers.
     */
    t_ptr = n_ptr;
    n_ptr = n_ptr->l_ptr;

    t_ptr->l_ptr = n_ptr->r_ptr;
    n_ptr->r_ptr = t_ptr;

    t_ptr->h = n_ptr->h - 1;
    return n_ptr;
}

/**
 * Left rotation.
 */
void* AVL_lr(struct avl_node* n_ptr){

    /**
     * 
     */
    struct avl_node* t_ptr = NULL;

    /**
     * Peramiter validation.
     */
    if(!n_ptr) return NULL;
    if(!n_ptr->r_ptr) return NULL;

    /**
     * Changes pointers.
     */
    t_ptr = n_ptr;
    n_ptr = n_ptr->r_ptr;

    t_ptr->r_ptr = n_ptr->l_ptr;
    n_ptr->l_ptr = t_ptr;

    t_ptr->h = n_ptr->h - 1;
    return n_ptr;
}

/**
 * Left, right rotation.
 */
void* AVL_lrr(struct avl_node* n_ptr){

    n_ptr->l_ptr = AVL_lr(n_ptr->l_ptr);
    return AVL_rr(n_ptr);
}

/**
 * Right, left rotation.
 */
void* AVL_rlr(struct avl_node* n_ptr){

    n_ptr->r_ptr = AVL_rr(n_ptr->r_ptr);
    return AVL_lr(n_ptr);
}

/**
 * Get diffence in node height. 
 */
int64_t AVL_getBalance(struct avl_node* n_ptr){

    if(!n_ptr) return 0;

    int64_t hl = (!n_ptr->l_ptr) ? 0 : n_ptr->l_ptr->h;
    int64_t hr = (!n_ptr->r_ptr) ? 0 : n_ptr->r_ptr->h;

    return hl - hr;
}

/**
 * Inserts a new node into the tree.
 */
int8_t AVL_insert(struct avl_node** n_pptr, int64_t key){

    /**
     * Create a new node if n_ptr is null.
     */
    if(!*n_pptr) return AVL_node_ini(n_pptr, key);
    
    /**
     * 
     */
    if((*n_pptr)->key < key){

        /**
         * Gose and add a new node to the right of the tree.
         */
        AVL_insert(&(*n_pptr)->r_ptr, key);
        (*n_pptr)->h = ((*n_pptr)->h <= (*n_pptr)->r_ptr->h) ? ((*n_pptr)->r_ptr->h + 0x01) : (*n_pptr)->h;
        
        /**
         * Right right case rotation is operation is perfromed.
         */
        if((AVL_getBalance(*n_pptr) < -1 ) && (key > (*n_pptr)->r_ptr->key)){

            *n_pptr = AVL_lr(*n_pptr);
            return 0;
        }
        
        /**
         * Right left case rotation is operation is perfromed.
         */
        if((AVL_getBalance(*n_pptr) < -1 ) && (key < (*n_pptr)->r_ptr->key)) *n_pptr = AVL_rlr(*n_pptr);
        return 0;
    }

    /**
     * Gose and add a new node to the left of the tree.
     */
    AVL_insert(&(*n_pptr)->l_ptr, key);
    (*n_pptr)->h = ((*n_pptr)->h <= (*n_pptr)->l_ptr->h) ? ((*n_pptr)->l_ptr->h + 0x01) : (*n_pptr)->h;

    /**
     * Left left case rotation is operation is perfromed.
     */
    if((AVL_getBalance(*n_pptr) > 1 ) && (key < (*n_pptr)->l_ptr->key)){

        *n_pptr = AVL_rr(*n_pptr);
        return 0;
    }
        
    /**
     * Left right case rotation is operation is perfromed.
     */
    if((AVL_getBalance(*n_pptr) > 1 ) && (key > (*n_pptr)->l_ptr->key)) *n_pptr = AVL_lrr(*n_pptr);
    return 0;
}

// /**
//  * Inserts a new node into the tree with iteration.
//  * (This is going to be a lot of work...)
//  */
// int8_t AVL_insert_i(struct avl_node** n_pptr, int64_t key){

//     int64_t hl = 0;
//     int64_t hr = 0;

//     /**
//      * Insert as a binary tree.
//      */
//     while(*n_pptr){

//         (*n_pptr)->h++;

//         hl = (!(*n_pptr)->l_ptr) ? 0 : (*n_pptr)->l_ptr->h;
//         hr = (!(*n_pptr)->r_ptr) ? 0 : (*n_pptr)->r_ptr->h;

//         /**
//          * Gose left on the tree. 
//          */
//         if((*n_pptr)->key > key){

//             // /**
//             //  * Left left case rotation is operation is perfromed.
//             //  * (works but the height is wrong!!!)
//             //  */
//             // if(((*n_pptr)->l_ptr && (key < (*n_pptr)->l_ptr->key)) && (((hl + 1) - hr) > 1)){

//             //     //(*n_pptr)->l_ptr->h++;
//             //     *n_pptr = AVL_rr(*n_pptr);
//             // }

//             n_pptr = &(*n_pptr)->l_ptr;
//             continue;
//         }

//         n_pptr = &(*n_pptr)->r_ptr;
//     }
    
//     AVL_node_ini(n_pptr, key);
//     return 0;
// }

/**
 * Convert to list.
 */

int8_t AVL_get_at_height(struct avl_node* n_ptr, int64_t h){

    if(!n_ptr) return -1;

    if(n_ptr->h == h){

        printf("\n[%ld]%ld)", n_ptr->h, n_ptr->key);
        return 0;
    }

    AVL_get_at_height(n_ptr->l_ptr, h);
    AVL_get_at_height(n_ptr->r_ptr, h);
    return 0;
}

/**
 * Write this AVL tree to a file. 
 */
int8_t AVL_write(const char* dir_ptr, AVL_Tree* tree_ptr){

    /**
     * 
     */
    int64_t h = 0;

    /**
     * 
     */
    if(!dir_ptr) return INVALIDPERAMITER;
    if(!tree_ptr) return INVALIDPERAMITER;

    /**
     * Use binary tree for the insert...
     */
    h = tree_ptr->n_ptr->h;

    while(h){

        printf("\n");
        AVL_get_at_height(tree_ptr->n_ptr, h);
        h--;
    }

    return 0;
}

/**
 * 
 */
void AVL_remove(struct avl_node* n_ptr, int64_t key){

    
}

/**
 * Read this AVL tree from a file. 
 */

/**
 * Meage two AVL trees. 
 */

/**
 * Split an AVL trees. 
 */

#endif

/**
 * If using the C++ implomentation, 
 * compile the following block.
 */
#ifdef __cplusplus


#endif