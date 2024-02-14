#include "leak_killer.h"

void	set_global(t_memory *new_head)
{
	t_memory	**head;

	head = get_global();
	*head = new_head;
}
