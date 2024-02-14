#include "leak_killer.h"

void	lfree(void *pointer)
{
	t_memory	*node;
	t_memory	*next_node;
	t_memory	*prev_node;

	node = *(get_global());
	prev_node = NULL;
	while (node && node->pointer != pointer)
	{
		prev_node = node;
		node = node->next;
	}
	if (!node)
	{
		free(pointer);
		return ;
	}
	next_node = node->next;
	free(node->pointer);
	if (prev_node)
		prev_node->next = next_node;
	else
		set_global(next_node);
	free(node);
}
