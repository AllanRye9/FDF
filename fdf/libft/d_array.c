#include "libft.h"

t_array_node	*ft_get_array_node(t_array *array, size_t i)
{
	size_t			j;
	t_array_node	*node;

	j = 0;
	if (array == 0)
		return (0);
	if (i >= array->length)
		return (0);
	node = array->head;
	while ((j < i) && (node != 0))
	{
		node = node->next;
		j++;
	}
	return (node);
}

void	*ft_get_elem(t_array *array, size_t index)
{
	void			*content;
	t_array_node	*node;

	content = 0;
	node = ft_get_array_node(array, index);
	if (node == 0)
		return (0);
	content = node->content;
	return (content);
}

/*
* Take an array and apply the f function, wich return pointers to result
* Return an array of size array->lengh contening pointers of f results
* [void *p1, void *p2, ...]
*/
void	**ft_map(t_array *array, void *(*f)(void *, int index))
{
	void			**results;
	size_t			i;
	t_array_node	*node;

	i = 0;
	if (!array)
		return (0);
	if (array->length == 0)
		return (0);
	node = array->head;
	results = ft_calloc(array->length, sizeof(void *));
	if (!results)
		return (0);
	while (i < array->length)
	{
		results[i] = f(node->content, i);
		node = node->next;
		i++;
	}
	return (results);
}

/*
 * Take an array and apply the f function on each element
 * Return (bool) true if f was applied
 */
bool	ft_for_each(t_array *array, void (*apply)(void *, int index))
{
	t_array_node	*node;
	size_t			i;

	i = 0;
	if (!array)
		return (0);
	if (array->length == 0)
		return (0);
	node = array->head;
	while (i < array->length && (node != 0))
	{
		apply(node->content, i);
		node = node->next;
		i++;
	}
	return (true);
}
