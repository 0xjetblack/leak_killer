#include "leak_killer.h"

t_memory	**get_global(void)
{
	static t_memory	*head;

	return (&head);
}
