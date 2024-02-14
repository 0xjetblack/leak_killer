#include "leak_killer.h"

t_memory	*track_memory(void *memory)
{
	t_memory	*node;
	t_memory	**old_head;

	old_head = get_global();
	node = (t_memory *)malloc(1 * sizeof(t_memory));
	if (!node)
		exit_error();
	node->pointer = memory;
	node->next = *old_head;
	set_global(node);
	return (node);
}
