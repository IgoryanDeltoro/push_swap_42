/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:51:31 by ibondarc          #+#    #+#             */
/*   Updated: 2024/11/20 02:31:22 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void print_stack_a(t_list *lst_a)
{
    printf("A\n");
    while (lst_a != NULL)
    {
        printf("[%d]\n", lst_a->data);
        lst_a = lst_a->next;
    }
}
static void print_stack_b(t_list *lst_b)
{
    printf("\nB\n");
    while (lst_b != NULL)
    {
        printf("[%d]\n", lst_b->data);
        lst_b = lst_b->next;
    }
}

static int push_swap(t_list **lst_a, t_list **lst_b)
{
    int ac_len;

    ac_len = (*lst_a)->argc - 1;
    if (ac_len == 2)
        sort_2_num(lst_a);
    if (ac_len == 3)
         sort_3_num(lst_a);
    if (ac_len >= 4 && ac_len <= 6)
        sort_4_6_num(lst_a, lst_b);
    if (ac_len > 6)
        sort_big_num(lst_a, lst_b);
    return (1);
}

static int    initial_stack(t_list **lst_a, int ac, char **av)
{
    t_list  *temp;
    int     i;
    int     num;
    
    i = 1;
    if (ac == 2)
    {
        ac = ft_count_words(av[1], ' ') + 1;
        av = ft_split(av[1], ' ');
        i = 0;
    }
    while (av[i])
    {
        num = ft_atoi(av[i]);
        if ((num == 0 && av[i][0] != 48) || has_duplicate(*lst_a, num))
            return (0);
        temp = ft_lstnew(num, ac);
        ft_lstadd_back(&(*lst_a), temp);
        i++;
    }
    return (1);
}

int main(int ac, char **av)
{
    t_list *stack_a;
    t_list *stack_b;
    int res;

    stack_a = NULL;
    stack_b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (printf("Error"), 1);
    res = initial_stack(&stack_a, ac, av);
    if (!res)
    {
        printf("Error\n");
        ft_lstclean(&stack_a);
        return (1);
    }
    else
        res = push_swap(&stack_a, &stack_b);
    if (!res)
        return (1);
    print_stack_a(stack_a);
    print_stack_b(stack_b);
    ft_lstclean(&stack_a);
    return (0);
}
