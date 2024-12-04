/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_huge_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:40:09 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/03 17:16:01 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_cheapest(t_list *stack_b)
{
	int		best_cheapest_value;
	t_list	*best_cheapest_node;

	if (!stack_b)
		return ;
	best_cheapest_value = INT_MAX;
	while (stack_b)
	{
		if (stack_b->push_cost < best_cheapest_value)
		{
			best_cheapest_value = stack_b->push_cost;
			best_cheapest_node = stack_b;
		}
		stack_b = stack_b->next;
	}
	best_cheapest_node->cheapest = 1;
}

void	set_cost(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		stack_b->push_cost = stack_b->curr_position;
		if (!(stack_b->before_median))
			stack_b->push_cost = len_b - (stack_b->curr_position);
		if (stack_b->target_node->before_median)
		{
			stack_b->push_cost += stack_b->target_node->curr_position;
		}
		else
			stack_b->push_cost += len_a - (stack_b->target_node->curr_position);
		stack_b = stack_b->next;
	}
}

void	set_target_node(t_list *stack_a, t_list *stack_b)
{
	t_list	*curr_a;
	t_list	*target;
	int		best_value;

	while (stack_b)
	{
		curr_a = stack_a;
		best_value = INT_MAX;
		while (curr_a)
		{
			if (curr_a->value > stack_b->value && curr_a->value < best_value)
			{
				best_value = curr_a->value;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_value == INT_MAX)
			stack_b->target_node = get_smallest(stack_a);
		else
			stack_b->target_node = target;
		stack_b = stack_b->next;
	}
}

void	sort_huge_num(t_list **stack_a, t_list **stack_b)
{
	int	size_a;

	if (!(*stack_a) || !stack_a)
		return ;
	size_a = ft_lstsize(*stack_a);
	while (size_a-- > 3)
		handle_actions(stack_a, stack_b, "pb");
	sort_3_num(stack_a, stack_b);
	while (*stack_b)
	{
		set_curr_position(*stack_a);
		set_curr_position(*stack_b);
		set_target_node(*stack_a, *stack_b);
		set_cost(*stack_a, *stack_b);
		set_cheapest(*stack_b);
		move_nodes(stack_a, stack_b);
	}
	set_curr_position(*stack_a);
	rotate_smallest(stack_a, stack_b, get_smallest(*stack_a));
}
