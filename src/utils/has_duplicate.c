/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:12:23 by ibondarc          #+#    #+#             */
/*   Updated: 2024/11/16 01:50:12 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int has_duplicate(t_list *lst, int new_value) 
{
    while (lst != NULL) 
    {
        if (lst->data == new_value)
            return (1);
        lst = lst->next;
    }
    return 0;
}
