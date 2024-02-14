#ifndef LEAK_KILLER_H
# define LEAK_KILLER_H

# include <stdlib.h>

typedef struct s_memory
{
	void			*pointer;
	struct s_memory	*next;
}	t_memory;

void		free_heap(void);					
t_memory	*track_memory(void *memory);
t_memory	*get_node(void *memory);	
void		set_global(t_memory *new_head);
t_memory	**get_global(void);
void		*lfmalloc(size_t size);					
void		lfree(void *pointer);					
void		exit_error(void);

#endif
