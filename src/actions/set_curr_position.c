/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_curr_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:33:26 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/04 11:46:52 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_curr_position(t_list *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->curr_position = i;
		if (i <= median)
			stack->before_median = 1;
		else
			stack->before_median = 0;
		stack = stack->next;
		++i;
	}
}
