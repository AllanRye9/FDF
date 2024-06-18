#include "../libft/libft.h"
#include "../includes/fdf.h"

void	free_stack(t_stack *stack)
{
	void	*content;

	if (!stack)
		return ;
	while (stack->length)
	{
		content = pop_s(stack);
		free(content);
	}
	free(stack);
	stack = NULL;
	return ;
}

void	free_array(void **array, size_t size)
{
	size_t	i;

	if (!array)
		return ;
	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
	return ;
}

void	ft_free_splitted(char **arr)
{
	size_t	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
}
