/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:02:46 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/03 17:21:17 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_node(t_list **stack_1, t_list **stack_2, char *str, bool flag)
{
	t_list	*first;
	t_list	*second;

	if (!(*stack_1) || !stack_1)
		return ;
	first = *stack_1;
	if ((*stack_1)->next)
	{
		second = (*stack_1)->next;
		second->prev = NULL;
	}
	else
		second = NULL;
	*stack_1 = second;
	if (*stack_2)
	{
		first->next = *stack_2;
		first->prev = NULL;
	}
	else
		first->next = NULL;
	*stack_2 = first;
	if (flag)
		print_actions(str);
}
