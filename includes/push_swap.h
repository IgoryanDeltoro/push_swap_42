/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:55:57 by ibondarc          #+#    #+#             */
/*   Updated: 2024/11/19 18:52:22 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				argc;
	int				idx;
	int				data;
	struct s_list	*next;
}					t_list;

///                 Utils
int					ft_atoi(const char *nptr);
int					ft_isdigit(int ac, char **av);
int					ft_strcmp(char *s1, char *s2);
int					ft_lstsize(t_list *lst);
int					has_duplicate(t_list *lst, int new_value);
int					ft_count_words(char const *s, char c);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclean(t_list **lst);
char				**ft_split(char const *s, char c);
int					ft_strlen(const char *s);
int					ft_strlcpy(char *dst, const char *src, int size);
t_list				*ft_lstnew(int num, int ac);
t_list				*ft_lstlast(t_list *lst);
////                Actions
void				ft_sa(t_list **lst_a);
void				ft_sb(t_list **lst_b);
void				ft_ss(t_list **lst_a, t_list **lst_b);
void				ft_ra(t_list **lst_a);
void				ft_rb(t_list **lst_b);
void				ft_rr(t_list **lst_a, t_list **lst_b);
void				ft_rra(t_list **lst_a);
void				ft_rrb(t_list **lst_b);
void				ft_rrr(t_list **lst_a, t_list **lst_b);
void    			ft_pa(t_list **lst_a, t_list **lst_b);
void    			ft_pb(t_list **lst_a, t_list **lst_b);
void				rotate_to_top(t_list **lst_a, int index);
int 				find_index(t_list *lst);
////                Handlers
int 				sort_2_num(t_list **lst_a);
int					sort_3_num(t_list **lst_a);
int 				sort_4_6_num(t_list **lst_a, t_list **lst_b);
int 				sort_big_num(t_list **lst_a, t_list **lst_b);

#endif
