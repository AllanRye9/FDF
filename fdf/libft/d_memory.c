#include "libft.h"

t_array	*ft_new_array(void)
{
	t_array	*array;

	array = (t_array *)ft_calloc(1, sizeof(t_array));
	if (array == 0)
		return (0);
	array->length = 0;
	array->head = 0;
	array->bottom = 0;
	array->type = e_array_normal;
	return (array);
}

/*
 * Push element to the end of Array works on non dic
 * Return (bool) true if space was found and content added
 */
bool	ft_push(t_array *array, void *content)
{
	t_array_node	*node;

	if (!array)
		return (false);
	node = (t_array_node *)ft_calloc(1, sizeof(t_array_node));
	if (!node)
		return (false);
	node->content = content;
	node->next = 0;
	if (array->length == 0)
	{
		array->head = node;
		array->bottom = node;
	}
	else
	{
		array->bottom->next = node;
		array->bottom = node;
	}
	array->length++;
	return (true);
}

/*
 * Push element to the top of Array works on non dic
 * Return (bool) true if space was found and content added
 */
bool	ft_unshift(t_array *array, void *content)
{
	t_array_node	*node;

	if (!array)
		return (false);
	node = (t_array_node *)ft_calloc(1, sizeof(t_array_node));
	if (!node)
		return (false);
	node->content = content;
	node->next = 0;
	if (array->length == 0)
	{
		array->head = node;
		array->bottom = node;
	}
	else
	{
		node->next = array->head;
		array->head = node;
	}
	array->length++;
	return (true);
}

/*
* Pop the last element in the array
* Return (void *) of the content
*/
void	*ft_pop(t_array *array)
{
	t_array_node	*node;
	void			*content;

	if (!array)
		return (0);
	if ((array->length == 0) || (array->bottom == 0))
		return (0);
	content = 0;
	node = array->bottom;
	if (array->length == 1)
	{
		content = node->content;
		array->bottom = 0;
		array->head = 0;
	}
	else if (array->length > 1)
	{
		content = node->content;
		array->bottom = ft_get_array_node(array, (array->length - 2));
	}
	array->length--;
	free(node);
	return (content);
}

/*
 * Free Array and content inside
 */
void	ft_free_d_array(t_array *array)
{
	void	*content;

	if (!array)
		return ;
	while (array->length)
	{
		content = ft_pop(array);
		free(content);
	}
	free(array);
	array = NULL;
	return ;
}
