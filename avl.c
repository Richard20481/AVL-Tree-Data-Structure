/**
 * Author: Richard.G
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
#include "../Headers/node.h"

/**
 * If using the C implomentation,
 * compile the following block.
 */
#ifndef __cplusplus

/**
 * 
 */
void avl_print(struct node* n_ptr){

    if(n_ptr){

        printf("\n(%ld)", n_ptr->key);
        avl_print(n_ptr->l_ptr);
        avl_print(n_ptr->r_ptr);
    }
}

/**
 * 
 */
void AVL_print(AVL_Tree* tree){

    printf("\nNumber of nodes is %lu", tree->n);
    printf("\nSize of node is (%lu)bytes.", tree->s);
    printf("\nTotal memory used is (%lu)bytes.\n", (tree->n * tree->s) + sizeof(struct avl));

    avl_print(tree->n_ptr);
}

/**
 * Might make inline??
 */
int8_t avl_insert(struct node** n_pptr, int64_t key, 
void* d_ptr, const size_t size){

    /**
     * 
     */
    while(*n_pptr){

        if((*n_pptr)->key < key){

            n_pptr = &(*n_pptr)->r_ptr;
            continue;
        }

        n_pptr = &(*n_pptr)->l_ptr;
    }

    return ini_node(n_pptr, key, d_ptr, size);
}

/**
 * Inserts a new node into the tree.
 * (API Abstraction interface...)
 */
int8_t AVL_insert(AVL_Tree* tree, int64_t key, void* d_ptr){ 

    int8_t err = 0;

    /**
     * 
     */
    if(AVL_contains(tree, key)) return DUPLICATEKEY;
    err = avl_insert(&tree->n_ptr, key, d_ptr, tree->s);

    if(!err)tree->n++;
    return err;
}

/**
 * Look for the data in the tree.
 * (API Abstraction interface...)
 */
void* AVL_find(AVL_Tree* tree_ptr, int64_t key){

    /**
     * 
     */
    struct node* t_ptr = NULL;

    /**
     * 
     */
    if(!tree_ptr) return NULL;
    if(!key) return NULL;

    t_ptr = tree_ptr->n_ptr;

    /**
     * 
     */
    while(t_ptr){

        //If the key match, return true.
        if(key == t_ptr->key) return t_ptr;

        /**
         * Go to right node.
         */
        if(t_ptr->key < key){
            
            t_ptr = t_ptr->r_ptr;
            continue;
        }
        
        //Else the left node.
        t_ptr = t_ptr->l_ptr;
    }

    return NULL;
}

/**
 * Look for the data in the tree.
 * (API Abstraction interface...)
 */
int8_t AVL_contains(AVL_Tree* tree_ptr, const int64_t key){

    /**
     * 
     */
    if(!tree_ptr) return FAILEDTOVALIDATE;
    if(!key) return FAILEDTOVALIDATE;

    /**
     * 
     */
    if(AVL_find(tree_ptr, key)) return 0x01;
    return 0x00;
}

/**
 * Merges two avl trees together into one tree.
 */
int8_t AVL_merge(void){

    return 0;
}

/**
 * Splits a avl tree into two smaller trees.
 */
int8_t AVL_split(void){

    return 0;
}

/**
 * (API Abstraction interface...)
 */
int8_t AVL_remove(AVL_Tree tree, void* d_ptr){


    return 0;
}

#endif

/**
 * If using the C++ implomentation, 
 * compile the following block.
 */
#ifdef __cplusplus


#endif