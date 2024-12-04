/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:48:40 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/04 12:07:23 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	whitespaces(const char *str, int *idx)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	*idx = i;
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	long	sign;
	long	result;

	result = 0;
	sign = whitespaces(nptr, &i);
	while (nptr[i])
	{
		if (!(nptr[i] >= 48 && nptr[i] <= 57))
			return (0);
		else
		{
			result = result * 10 + (nptr[i] - 48);
			i++;
		}
	}
	result *= sign;
	if (result < INT_MIN || result > INT_MAX)
		return (0);
	return (result);
}
