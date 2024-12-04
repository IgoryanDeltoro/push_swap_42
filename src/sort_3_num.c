/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:24:55 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/03 17:16:18 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_num(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	second;
	int	third;

	if (!(*stack_a) || !stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && first < third)
		handle_actions(stack_a, stack_b, "sa");
	if (second < first && second > third)
	{
		handle_actions(stack_a, stack_b, "sa");
		handle_actions(stack_a, stack_b, "rra");
	}
	if (third < first && third > second)
		handle_actions(stack_a, stack_b, "ra");
	if (third < second && third > first)
	{
		handle_actions(stack_a, stack_b, "sa");
		handle_actions(stack_a, stack_b, "ra");
	}
	if (first < second && first > third)
		handle_actions(stack_a, stack_b, "rra");
}
