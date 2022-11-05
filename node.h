/**
 * Author: Richard.G
 * Decluration for a node structure.
 */

//80 line limit!!!
////////////////////////////////////////////////////////////////

/**
 * 
 */
#ifndef NODE_LIB
#define NODE_LIB

/**
 * C standard librarys included.
 */
#include <stdint.h> //
#include <malloc.h> //
#include <string.h> //

/**
 * Constent informal macros.
 */
#define NODESIZE (sizeof(struct node))

/**
 * Error macros.
 */
#define FAILEDTOVALIDATE    -0x01   //Failed to validate.
#define FAILEDTOALLOCATE    -0x02   //Failed to allocate.
#define DUPLICATEKEY        -0x03   //Duplicate key.
 
/**
 * Node structure declaration.
 * (uses in binary trees or similer data structures.)
 */
struct node{

    int64_t key;            //Node key.

    struct node* l_ptr;     //Pointer to the left element.
    struct node* r_ptr;     //Pointer to the right element.
    void* d_ptr;            //Pointer to the data of this node.
};

/**
 * Creates a new node with the data and returns true if 
 * the initialization was successfully performed.
 */
int8_t ini_node(struct node** n_pptr, int64_t key, void* d_ptr, 
const size_t size){

    /**
     * Parameter validation.
     */
    if(!n_pptr) return FAILEDTOVALIDATE;
    if(!d_ptr)  return FAILEDTOVALIDATE;
    if(!size)   return FAILEDTOVALIDATE;
    if(!key)    return FAILEDTOVALIDATE;

    /**
     * Creates the new node.
     */
    *n_pptr = (struct node*)malloc(NODESIZE);
    if(!*n_pptr) return FAILEDTOALLOCATE;

    /**
     * Sets the new nodes attributes.
     */
    (*n_pptr)->l_ptr = NULL;
    (*n_pptr)->r_ptr = NULL;
    (*n_pptr)->key = key;

    /**
     * Allocate space for the nodes data.
     */
    (*n_pptr)->d_ptr = malloc(size);
    if(!(*n_pptr)->d_ptr) return FAILEDTOALLOCATE;

    /**
     * Set the nodes data. 
     */
    if(!memcpy((*n_pptr)->d_ptr, d_ptr, size)){

        free((*n_pptr)->d_ptr);
        return FAILEDTOALLOCATE;
    }

    return 0x00;
}

/**
 * Deletes a node with returns true if the deleation 
 * was successfully performed.
 */
int8_t del_node(struct node** n_pptr){

    /**
     * 
     */
    if(!n_pptr) return FAILEDTOVALIDATE;

    /**
     * 
     */
    (*n_pptr)->l_ptr = NULL;
    (*n_pptr)->r_ptr = NULL;

    /**
     * 
     */
    if((*n_pptr)->d_ptr){

        free((*n_pptr)->d_ptr);
        (*n_pptr)->d_ptr = NULL;
    }

    return 0x01;
}

// /**
//  * Perfromes a right right rotation on a node in a tree data structure. 
//  */
// int8_t rotate_rr(struct node* n_ptr){



//     return 0;
// }

#endif