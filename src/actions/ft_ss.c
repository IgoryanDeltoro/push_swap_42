/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:23:20 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/15 20:32:45 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_ss(t_list **lst_a, t_list **lst_b)
{    
    if (!lst_a || !lst_b || !(*lst_a) || !(*lst_b))
        return ;
    printf("ss\n");
    ft_sa(lst_a);
    ft_sb(lst_b);
}