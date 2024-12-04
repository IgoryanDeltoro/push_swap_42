/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:55:57 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/04 11:00:23 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				curr_position;
	int				push_cost;
	int				before_median;
	int				cheapest;
	struct s_list	*prev;
	struct s_list	*next;
	struct s_list	*target_node;
}					t_list;

///                 Utils
int					ft_atoi(const char *nptr);
int					ft_strcmp(char *s1, char *s2);
int					ft_lstsize(t_list *lst);
int					has_duplicate(t_list *lst, int new_value);
int					ft_count_words(char const *s, char c);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstclean(t_list **lst);
char				**ft_split(char const *s, char c);
int					ft_strlen(const char *s);
int					ft_strlcpy(char *dst, const char *src, int size);
t_list				*ft_lstnew(int num);
t_list				*ft_lstlast(t_list *lst);
////                Actions
void				swap_node(t_list **stack, char *str, bool flag);
void				rotate_node(t_list **stack, char *str, bool flag);
void				reverse_rotate_node(t_list **stack, char *str, bool flag);
void				push_node(t_list **stack_1, t_list **stack_2, char *str,
						bool flag);
void				handle_actions(t_list **stack_a, t_list **stack_b,
						char *str);
void				print_actions(char *str);
void				rotate_smallest(t_list **stack_a, t_list **stack_b,
						t_list *smallest);
void				move_nodes(t_list **stack_a, t_list **stack_b);
int					is_stack_sorted(t_list *stack);
void				set_curr_position(t_list *stack);
t_list				*get_smallest(t_list *stack);
t_list				*get_cheapest(t_list *stack);
////                Handlers
void				sort_2_num(t_list **stack_a, t_list **stack_b);
void				sort_3_num(t_list **stack_a, t_list **stack_b);
void				sort_huge_num(t_list **stack_a, t_list **stack_b);

#endif
