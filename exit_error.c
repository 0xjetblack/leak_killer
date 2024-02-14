#include "leak_killer.h"

void	exit_error(void)
{
	free_heap();
	exit(1);
}
