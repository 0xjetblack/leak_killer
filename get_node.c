#include "leak_killer.h"

t_memory	*get_node(void *memory)
{
	t_memory	*node;

	node = *(get_global());
	while (node && node->pointer != memory)
		node = node->next;
	return (node);
}
