#ifndef ARRAY_UTILS_H
# define ARRAY_UTILS_H
# include <stdbool.h>
# include <stdlib.h>

bool	is_sorted_asc(int arr[], int n);
bool	is_sorted_desc(int arr[], int n);
int		type_of_sort(int arr[], int n);
int		*ft_slice_int(const int original[], int begin, int end);
#endif
