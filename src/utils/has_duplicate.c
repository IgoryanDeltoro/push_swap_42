/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:12:23 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/04 10:56:04 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	has_duplicate(t_list *stack, int new_value)
{
	while (stack != NULL)
	{
		if (stack->value == new_value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
