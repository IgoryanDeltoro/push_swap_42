/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:27:54 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/14 03:07:37 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_ra(t_list **lst_a)
{
    t_list	*first;
    t_list	*temp;
    
    if (!(*lst_a) || !(*lst_a)->next)
        return ;
    printf("ra\n");
    first = *lst_a;
    *lst_a = (*lst_a)->next;
    temp = *lst_a;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = first;
    first->next = NULL;
}
