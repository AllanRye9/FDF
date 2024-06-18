#include "libft.h"

static int	*run_copy(int begin, int end, const int original[])
{
	int				i;
	int				j;
	int				*copy;

	i = 0;
	j = 0;
	copy = (int *)malloc(sizeof(int) * (end - begin));
	if (!copy)
		return (NULL);
	if (original)
	{
		while (original[i])
		{
			if ((i >= begin) && (i < end))
			{
				copy[j] = original[i];
				j++;
			}
			if (i == end)
				break ;
			i++;
		}
	}
	return (copy);
}

int	*ft_slice_int(const int original[], int begin, int end)
{
	unsigned int	size;
	int				*copy;

	size = end - begin;
	copy = NULL;
	if (size > 0)
		copy = run_copy(begin, end, original);
	return (copy);
}
