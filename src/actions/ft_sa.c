/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:37:38 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/15 20:30:42 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_sa(t_list **lst_a)
{
    int temp;
    
    if (!lst_a || !(*lst_a) || !(*lst_a)->next)
        return ;
    printf("sa\n");
    temp = (*lst_a)->data;
    (*lst_a)->data = (*lst_a)->next->data;
    (*lst_a)->next->data = temp;
}