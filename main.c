/**
 * Author: Richard.G
 * Discription: 
 */

/**
 * C header files.
 */
#include <stdio.h>  //C standard io library.

/**
 * Programmer defined header files.
 */
#include "../Headers/avl.h"

/**
 * https://www.youtube.com/watch?v=A3JZinzkMpk
 * https://en.wikipedia.org/wiki/Tree_rotation
 * https://en.wikipedia.org/wiki/Tree_rotation#/media/File:Tree_Rebalancing.gif
 */

/*
 * Main function.
 */
int main(int argn, char* argv[]){

    int8_t err = 0;
    int32_t a = 0;

    AVL_Tree tree;

    tree.n_ptr = NULL;
    tree.n = 0;
    tree.s = sizeof(int);

    

    a = 10;
    err = AVL_insert(&tree, a, &a);

    a = 15;
    err = AVL_insert(&tree, a, &a);

    a = 5;
    err = AVL_insert(&tree, a, &a);

    printf("\n[%d]", AVL_contains(&tree, 5));
    AVL_print(&tree);
    
    return 0;
}