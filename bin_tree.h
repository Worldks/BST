#ifndef BIN_TREE_SENTRY
#define BIN_TREE_SENTRY
#include <stdlib.h>
#include <stdio.h>

struct bin_tree;
typedef struct bin_tree* bin_tree_ptr;

bin_tree_ptr bin_tree_init();
int Sum_elements(const bin_tree_ptr tree);
int addToTree(bin_tree_ptr tree, int value);
int IsInTree(bin_tree_ptr tree, int value);
#endif
