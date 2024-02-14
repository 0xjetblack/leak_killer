#include "leak_killer.h"

void	*lfmalloc(size_t size)
{
	void	*allocated;

	allocated = malloc(size);
	if (!allocated)
		exit_error();
	track_memory(allocated);
	return (allocated);
}
