
#include "vbc.h"

int main(int argc, char **argv)
{
	t_node *node;

	if (argc != 2)
		return (1);
	if (!validate_str(argv[1]))
		return (1);
	node = construct(argv[1]);
	if (!node)
	{
		printf("OOOPS");
		return (1);
	}
	write_tree(node);
	printf("%zu\n", walk_tree(node));
}
