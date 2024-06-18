#include "libft.h"

t_array	*ft_new_dic(void)
{
	t_array	*array;

	array = (t_array *)ft_calloc(1, sizeof(t_array));
	if (array == 0)
		return (0);
	array->length = 0;
	array->head = 0;
	array->bottom = 0;
	array->type = e_array_dic;
	return (array);
}

/*
 * Get (t_dic_node *) elem form disctionary if key match
 * Return a key (char *) and (void *) content
 */
t_dic_node	*ft_elem_dic(t_array *array, char *key)
{
	size_t		i;
	t_dic_node	*dic_entry;
	size_t		len;
	char		*key_i;

	i = 0;
	if (!array)
		return (0);
	if (array->type != e_array_dic)
		return (0);
	len = ft_strlen(key);
	while ((i < array->length) && (len > 0))
	{
		dic_entry = (t_dic_node *)ft_get_elem(array, i);
		if (dic_entry == 0)
			break ;
		key_i = dic_entry->key;
		if ((ft_strncmp(key_i, key, len) == 0) && (len == ft_strlen(key_i)))
			return (dic_entry);
		i++;
	}
	return (0);
}

/*
 * Push element to the end of Array works on non dic
 * Return (bool) true if space was found and content added
 * Return false if key already exist or no space
 * saved as ["key"] = void *content
 */
bool	ft_push_to_dic(t_array *array, char *key, void *content)
{
	t_dic_node		*dic_entry;

	if (!array)
		return (false);
	if (array->type != e_array_dic)
		return (false);
	if (ft_elem_dic(array, key) != 0)
		return (false);
	dic_entry = (t_dic_node *)ft_calloc(1, sizeof(t_dic_node));
	if (!dic_entry)
		return (false);
	dic_entry->content = content;
	dic_entry->key = key;
	ft_push(array, dic_entry);
	return (true);
}

/*
 * Free Dictionary key and content inside are free
 */
void	ft_free_dic(t_array *array)
{
	void		*content;
	t_dic_node	*node;

	if (!array)
		return ;
	while (array->length)
	{
		node = (t_dic_node *)ft_pop(array);
		content = node->content;
		free(content);
		free(node->key);
		free(node);
	}
	free(array);
	array = NULL;
	return ;
}

/*
 * Take a dictionary and apply the f function, witch return pointers to result
 * Return an array of size array->length containing pointers of f results
 * [void *p1, void *p2, ...] that need to be free after usage
 */
void	**ft_map_d(t_array *arr, void *(*f)(void *c, char *key, size_t i))
{
	void			**results;
	size_t			i;
	t_array_node	*node;
	t_dic_node		*node_key;

	i = 0;
	if (!arr)
		return (0);
	if (!arr->length)
		return (0);
	node = arr->head;
	results = ft_calloc(arr->length, sizeof(void *));
	if (!results)
		return (0);
	while ((i < arr->length) && (node != 0))
	{
		node_key = node->content;
		results[i] = f(node_key->content, node_key->key, i);
		node = node->next;
		i++;
	}
	return (results);
}
