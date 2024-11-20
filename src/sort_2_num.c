/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:58:33 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/19 18:15:51 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int sort_2_num(t_list **lst_a)
{
    if (!lst_a || !(*lst_a) || !(*lst_a)->next)
        return (0);
    if ((*lst_a)->data > (*lst_a)->next->data)
        ft_sa(lst_a);
    return (1);
}