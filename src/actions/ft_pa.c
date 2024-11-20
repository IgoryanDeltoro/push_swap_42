/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:02:46 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/15 18:39:53 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_pa(t_list **lst_a, t_list **lst_b)
{
    t_list  *first;
    t_list  *second;
    
     if (!(*lst_b) || !lst_b)
        return ;
    printf("pa\n");
    first = *lst_b;
    if ((*lst_b)->next)
        second = (*lst_b)->next;
    else
        second = NULL;
    *lst_b = second;
    if (*lst_a)
        first->next = *lst_a;
    else
        first->next = NULL;
    *lst_a = first;
}