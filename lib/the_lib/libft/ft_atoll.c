/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:40:24 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/20 23:50:29 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static void	get_sign(const char *str, int *sign, size_t *i)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoll(const char *str, long long *result)
{
	long long	n;
	size_t		i;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	get_sign(str, &sign, &i);
	if (str[i] == '\0')
		return (1);
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (n > 922337203685477580
			|| (n == 922337203685477580 && sign == 1 && str[i] > '7')
			|| (n == 922337203685477580 && sign == -1 && str[i] > '8'))
			return (1);
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (1);
	*result = n * (long long)sign;
	return (0);
}

// int main()
// {
// 	char *str = "0";//"9223372036854775807";
// 	long long result;
// 	printf("atoll(%s) return: %i\tresult: %lld\n"
//	, str, ft_atoll(str, &result), result);
// 	return (0);
// }
