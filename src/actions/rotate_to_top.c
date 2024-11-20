/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:44:57 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/19 17:45:08 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void rotate_to_top(t_list **lst_a, int index) 
{
    int a_len = ft_lstsize(*lst_a);
    
    if (index <= a_len / 2) 
    {
        while (index-- > 0)
            ft_ra(lst_a);
    }
    else 
    {
        index = a_len - index;
        while (index-- > 0)
            ft_rra(lst_a);
    }
}