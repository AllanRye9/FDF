#ifndef DYNAMIC_ARRAYS_H
# define DYNAMIC_ARRAYS_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_array_node
{
	void				*content;
	struct s_array_node	*next;
}	t_array_node;

typedef enum e_array_type
{
	e_array_normal,
	e_array_dic,
}	t_array_type;

typedef struct s_array
{
	size_t			length;
	t_array_type	type;
	t_array_node	*head;
	t_array_node	*bottom;
}	t_array;

typedef struct s_dic_node
{
	void				*content;
	char				*key;
}	t_dic_node;

t_array			*ft_new_array(void);
t_array			*ft_new_dic(void);
bool			ft_push(t_array *array, void *content);
bool			ft_push_to_dic(t_array *array, char *key, void *content);
bool			ft_unshift(t_array *array, void *content);
void			*ft_pop(t_array *array);
void			ft_free_d_array(t_array *array);
void			ft_free_dic(t_array *array);
t_array_node	*ft_get_array_node(t_array *array, size_t i);
void			*ft_get_elem(t_array *array, size_t index);
void			*ft_del_elem(t_array *array, size_t i);
t_dic_node		*ft_elem_dic(t_array *array, char *key);
void			**ft_map(t_array *array, void *(*f)(void *, int index));
void			**ft_map_d(t_array *arr, void *(*f)(void *, char *, size_t i));
bool			ft_for_each(t_array *array, void (*apply)(void *, int index));

#endif
