/**
 * 
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
    AVL_ini(&tree, sizeof(int));

    AVL_insert(&tree.n_ptr, 50);
    AVL_insert(&tree.n_ptr, 60);
    AVL_insert(&tree.n_ptr, 70);
    AVL_insert(&tree.n_ptr, 80);
    AVL_insert(&tree.n_ptr, 90);
    AVL_insert(&tree.n_ptr, 100);

    AVL_insert(&tree.n_ptr, 71);
    AVL_insert(&tree.n_ptr, 72);

    // AVL_insert(&tree.n_ptr, 40);
    // AVL_insert(&tree.n_ptr, 30);
    // AVL_insert(&tree.n_ptr, 20);
    // AVL_insert(&tree.n_ptr, 10);

    AVL_write("hello.txt", &tree);
    AVL_print(tree.n_ptr);

    return 0;
}