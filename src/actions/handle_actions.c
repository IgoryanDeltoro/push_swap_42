/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:46:54 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/03 14:27:49 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	handle_rest_actions(t_list **stack_a, t_list **stack_b, char *str);

void	handle_actions(t_list **stack_a, t_list **stack_b, char *str)
{
	if ((ft_strcmp(str, "sa")) == 0)
		swap_node(stack_a, str, true);
	else if ((ft_strcmp(str, "sb")) == 0)
		swap_node(stack_b, str, true);
	else if ((ft_strcmp(str, "ss")) == 0)
	{
		swap_node(stack_a, str, false);
		swap_node(stack_b, str, true);
	}
	else if ((ft_strcmp(str, "pa")) == 0)
		push_node(stack_b, stack_a, str, true);
	else if ((ft_strcmp(str, "pb")) == 0)
		push_node(stack_a, stack_b, str, true);
	else
		handle_rest_actions(stack_a, stack_b, str);
}

static void	handle_rest_actions(t_list **stack_a, t_list **stack_b, char *str)
{
	if ((ft_strcmp(str, "ra")) == 0)
		rotate_node(stack_a, str, true);
	else if ((ft_strcmp(str, "rb")) == 0)
		rotate_node(stack_b, str, true);
	else if ((ft_strcmp(str, "rr")) == 0)
	{
		rotate_node(stack_a, str, false);
		rotate_node(stack_b, str, true);
	}
	else if ((ft_strcmp(str, "rra")) == 0)
		reverse_rotate_node(stack_a, str, true);
	else if ((ft_strcmp(str, "rrb")) == 0)
		reverse_rotate_node(stack_b, str, true);
	else if ((ft_strcmp(str, "rrr")) == 0)
	{
		reverse_rotate_node(stack_a, str, false);
		reverse_rotate_node(stack_b, str, true);
	}
}
