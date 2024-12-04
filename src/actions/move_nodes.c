/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:30:36 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/04 11:41:36 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	do_both_rotations(t_list **stack_a, t_list **stack_b,
		t_list *cheapest, bool flag)
{
	while (*stack_a != cheapest->target_node && *stack_b != cheapest)
	{
		if (flag)
			handle_actions(stack_a, stack_b, "rr");
		else
			handle_actions(stack_a, stack_b, "rrr");
	}
	set_curr_position(*stack_a);
	set_curr_position(*stack_b);
}

static void	do_rotations(t_list **stack_1, t_list **stack_2, t_list *top_node,
		bool flag)
{
	while (*stack_1 != top_node)
	{
		if (flag)
		{
			if (top_node->before_median)
				handle_actions(stack_1, stack_2, "ra");
			else
				handle_actions(stack_1, stack_2, "rra");
		}
		else
		{
			if (top_node->before_median)
				handle_actions(stack_2, stack_1, "rb");
			else
				handle_actions(stack_2, stack_1, "rrb");
		}
	}
}

void	move_nodes(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = get_cheapest(*stack_b);
	if (cheapest->before_median && cheapest->target_node->before_median)
		do_both_rotations(stack_a, stack_b, cheapest, true);
	if (!(cheapest->before_median) && !(cheapest->target_node->before_median))
		do_both_rotations(stack_a, stack_b, cheapest, false);
	do_rotations(stack_a, stack_b, cheapest->target_node, true);
	do_rotations(stack_b, stack_a, cheapest, false);
	handle_actions(stack_a, stack_b, "pa");
}
