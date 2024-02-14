#include "leak_killer.h"

void	free_heap(void)
{
	t_memory	*node;
	t_memory	*tmp;

	node = *(get_global());
	while (node)
	{
		tmp = node->next;
		free(node->pointer);
		free(node);
		node = tmp;
	}
	set_global(NULL);
}
