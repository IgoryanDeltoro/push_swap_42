/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:48:14 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/15 18:41:33 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    ft_rrr(t_list **lst_a, t_list **lst_b)
{
    if (!(*lst_a) || !(*lst_b) || !lst_a || !lst_b)
		return ;
    printf("rrr\n");
	ft_rra(lst_a);
	ft_rrb(lst_b);
}
