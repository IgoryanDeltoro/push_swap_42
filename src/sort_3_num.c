/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:24:55 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/19 18:12:18 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int sort_3_num(t_list **lst)
{
    int first;
    int second;
    int third;
    
    if (!(*lst) || !lst || !(*lst)->next || !(*lst)->next->next)
        return (0);
    first = (*lst)->data;
    second = (*lst)->next->data;
    third = (*lst)->next->next->data;
    if (first > second && first < third)
        ft_sa(lst);
    if (second < first && second > third)
    {
        ft_sa(lst);
        ft_rra(lst);
    }
    if (third < first && third > second)
        ft_ra(lst);
    if (third < second && third > first)
    {
        ft_sa(lst);
        ft_ra(lst);
    }
    if (first < second && first > third)
        ft_rra(lst);
    return (1);
}
