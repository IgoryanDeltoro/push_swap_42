/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_6_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:05:10 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/19 18:50:12 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int sort_4_6_num(t_list **lst_a, t_list **lst_b)
{
    if (!(*lst_a) || !lst_a)
        return (0);
    while (ft_lstsize(*lst_a) > 3)
    {
        rotate_to_top(lst_a, find_index(*lst_a));
        ft_pb(lst_a, lst_b);
    }
    sort_3_num(lst_a);
    while (ft_lstsize(*lst_b) != 0)
    {
        ft_pa(lst_a, lst_b);
    }
    return (1);
}