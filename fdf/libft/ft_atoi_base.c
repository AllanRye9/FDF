/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oallan <oallan@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:51:14 by oallan            #+#    #+#             */
/*   Updated: 2023/12/30 16:15:20 by oallan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

static int get_digit(char c, int b)
{
    int m;
    if (b <= 10)
        m = c + '0';
    else
        m = 10 + c - 'a';
    if (c >= '0' && c <= '9' && c <= m)
        return (c - '0');
    else if (c >= 'a' && c <= 'f' && c <= m)
        return (10 + c - 'a');
    else
        return (-1);   
}

int ft_atoi_base(char *str, int str_base)
{
    int result;
    int sign;
    int digit;

    result = 0;
    sign = 1;

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while((digit = get_digit(to_lower(*str), str_base)) >= 0)
    {
        result = (result * str_base) + (digit * sign);
        str++;
    }
    return (result);
}
