/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:34:32 by ibondarc          #+#    #+#             */
/*   Updated: 2024/11/13 17:00:07 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_isdigit(int ac, char **av)
{
    int i;
    int j;
        
    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] == '-')
                j++;
            if (!(av[i][j] >= 48 && av[i][j] <= 57))
		        return (0);
            j++;
        }
        i++;
    }
	return (1);
}