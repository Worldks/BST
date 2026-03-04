#include <stdio.h>
#include "bin_tree.h"

void clear_input_buffer()
{
	int c;
	while((c = getchar()) != '\n' && c != EOF)
		{}
}

void bin_tree_example(bin_tree_ptr tree) /* Test binary tree operatins */
{
	int number;
	while(scanf("%d", &number) == 1){
		addToTree(tree, number);
	}
	number = Sum_elements(tree);
	printf("\nSum of elements in tree: %d\n", number);
	printf("Check if number in tree\n");
	/*fflush(stdin);	/* Clear standart input. Not working. */
	clear_input_buffer();
	while(scanf("%d", &number) == 1){ /* Not correct buffer */
		number = IsInTree(tree, number);
		if(number)
			printf("Yes\n");
		else
			printf("No\n");
	}
}

void solve_task()
{
	bin_tree_ptr tree;
	tree = bin_tree_init();
	bin_tree_example(tree);
}

int main(int argc, char **argv)
{
	solve_task();
	return 0;
}
