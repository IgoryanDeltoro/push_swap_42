/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:51:46 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/15 19:05:23 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_pb(t_list **lst_a, t_list **lst_b)
{
    t_list  *first;
    t_list  *second;
    
    if (!(*lst_a) || !lst_a)
        return ;
    printf("pb\n");
    first = *lst_a;
    if ((*lst_a)->next)
        second = (*lst_a)->next;
    else
        second = NULL;
    *lst_a = second;
    if (*lst_b)
        first->next = *lst_b;
    else
        first->next = NULL;
    *lst_b = first;
}