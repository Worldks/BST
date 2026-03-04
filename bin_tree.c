#include "bin_tree.h"

struct tree_node {
	int data;
    struct tree_node *left, *right;
};

struct bin_tree {
	struct tree_node *root;
};

#if DEBUG
static void print_tree(const struct tree_node *root)
{
	if(root == NULL)
		return;
	print_tree(root->left);
	printf("%d ", root->data);
	print_tree(root->right);
}
#endif

static int bin_tree_SumElements(const struct tree_node *node_tree)
{
	if(!node_tree)
		return 0;
	else {
		return bin_tree_SumElements(node_tree->left) + node_tree->data
			   		+ bin_tree_SumElements(node_tree->right);
	}
}

static struct tree_node **SearchTree(struct tree_node **root, int value)
{
	if(*root == NULL || (*root)->data == value)
		return root;
	else if(value < (*root)->data)
		return SearchTree(&((*root)->left), value);
	else
		return SearchTree(&((*root)->right), value);
}

bin_tree_ptr bin_tree_init()
{
	bin_tree_ptr tree;
	tree = malloc(sizeof(bin_tree_ptr));
	tree->root = NULL;
	return tree;
}

int Sum_elements(const bin_tree_ptr tree)
{
	return bin_tree_SumElements(tree->root);
}

int addToTree(bin_tree_ptr tree, int value)
{
	struct tree_node **node;
	node = SearchTree(&(tree->root), value);
	if(*node == NULL) {
		struct tree_node *tmp;
		tmp = malloc(sizeof(struct tree_node));
		tmp->data = value;
		tmp->left = tmp->right = NULL;
		*node = tmp;
		#if DEBUG
		printf("Tree after additing %d \n", value);
		print_tree(tree->root);
		#endif
		return 1;
	} else
		return 0;
}

int IsInTree(bin_tree_ptr tree, int value)
{
	struct tree_node **node;
	node = SearchTree(&(tree->root), value);
	if(*node == NULL)
		return 0;
	else
		return 1;
}
