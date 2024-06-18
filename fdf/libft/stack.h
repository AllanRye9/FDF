#ifndef STACK_H
# define STACK_H
# define MIN_INT_VALUE -2147483648
# define MAX_INT_VALUE 2147483647
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	void				*content;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	int				length;
	int				current;
	t_stack_node	*head;
	t_stack_node	*bottom;
}	t_stack;

t_stack			*create_stack(void);
// push value on the stack return true when pushed (false)
bool			push_s(t_stack *stack, void *content);
// return the pointer to value inside or 0
void			*pop_s(t_stack *stack);
// return the head value without destroying the node (error = MIN_VALUE)
void			*peak(t_stack *stack);
// return an Array of results of callback function without changing the stack
int				*map_stack_i(t_stack *stack, int (*apply)(void *, int index));
// apply function on every element f(*content, index)
bool			for_each_s(t_stack *stack, void (*apply)(void *, int i));
// (greedy) get the next ellement according to current value in t_stack
t_stack_node	*get_next(t_stack *stack);
// swap the first 2 elements at the top of stack (nothing if stack->length <= 1)
bool			swap_stack(t_stack *stack);
// shift up by 1 all elements of the stack return true (false if errors)
bool			rotate_stack(t_stack *stack);
// shift down by 1 all elements of the stack return true (false if errors)
bool			ft_reverse_rot(t_stack *stack);

#endif
