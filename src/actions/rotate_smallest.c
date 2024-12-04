/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_smallest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:44:57 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/04 12:05:07 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_smallest(t_list **stack_a, t_list **stack_b, t_list *smallest)
{
	if (smallest->before_median)
	{
		while (*stack_a != smallest)
			handle_actions(stack_a, stack_b, "ra");
	}
	else
	{
		while (*stack_a != smallest)
			handle_actions(stack_a, stack_b, "rra");
	}
}
