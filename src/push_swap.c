/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:51:31 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/04 11:42:23 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	freed_memory(char **arr, int len)
{
	int	i;

	i = 0;
	if (arr[0][0] == '.')
	{
		return ;
	}
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	stack_len;

	if (is_stack_sorted(*stack_a))
	{
		stack_len = ft_lstsize(*stack_a);
		if (stack_len == 2)
			sort_2_num(stack_a, stack_b);
		if (stack_len == 3)
			sort_3_num(stack_a, stack_b);
		if (stack_len > 3)
			sort_huge_num(stack_a, stack_b);
	}
}

static int	initial_stack(t_list **stack_a, int ac, char **av)
{
	int	i;
	int	num;

	i = 1;
	if (ac == 2)
	{
		ac = ft_count_words(av[1], ' ') + 1;
		av = ft_split(av[1], ' ');
		if (!av)
			return (0);
		i = 0;
	}
	while (av[i])
	{
		num = ft_atoi(av[i]);
		if ((num == 0 && av[i][0] != 48) || has_duplicate(*stack_a, num))
		{
			freed_memory(av, ac - 1);
			return (0);
		}
		ft_lstadd_back(stack_a, ft_lstnew(num));
		i++;
	}
	freed_memory(av, ac - 1);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		res;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (print_actions("Error"), 1);
	res = initial_stack(&stack_a, ac, av);
	if (!res)
	{
		print_actions("Error");
		ft_lstclean(&stack_a);
		return (1);
	}
	push_swap(&stack_a, &stack_b);
	ft_lstclean(&stack_a);
	return (0);
}
