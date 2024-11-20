/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:47:17 by igoryan           #+#    #+#             */
/*   Updated: 2024/11/19 18:09:19 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int find_index(t_list *lst) 
{
    int i;
    int index;
    int smallest;
    
    i = 1;
    smallest = lst->data;
    while (lst->next != NULL)
    {
        if (smallest > lst->next->data)
        {
            smallest = lst->next->data;
            index = i;
        }
        lst = lst->next;
        i++;
    }
    return index;
}