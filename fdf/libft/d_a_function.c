#include "libft.h"

static void	*ft_del_elem_suite(t_array *array, size_t i)
{
	t_array_node	*before_node;
	t_array_node	*node;
	t_array_node	*next_node;
	void			*content;

	content = NULL;
	node = ft_get_array_node(array, i);
	next_node = ft_get_array_node(array, i + 1);
	if (node)
		content = node->content;
	if (i == 0)
		array->head = next_node;
	else if (i >= 1)
	{
		if (node == array->head)
			array->head = next_node;
		else
		{
			before_node = ft_get_array_node(array, i - 1);
			before_node->next = next_node;
		}
	}
	free(node);
	array->length--;
	return (content);
}

/*
 * Pop element from the array and return the pointer of the content
 * can be a t_dic_node in case of dictionary
 */
void	*ft_del_elem(t_array *array, size_t i)
{
	void			*content;

	if (array == 0)
		return (0);
	if (i >= array->length)
		return (0);
	if ((array->length == 1) || (i == (array->length - 1)))
		content = ft_pop(array);
	else
		content = ft_del_elem_suite(array, i);
	return (content);
}
