/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseiv <eseiv@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:35:10 by eseiv             #+#    #+#             */
/*   Updated: 2022/03/19 20:16:21 by eseiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_push
{
	int	*stack_a;
	int	*stack_b;
	int	stack_a_size;
	int	stack_b_size;
	int	stack_a_quarter;
	int	stack_a_midpoint;
}	t_swap;

void	ft_pa(t_swap *s, int flag);
void	ft_pb(t_swap *s, int flag);
void	ft_sa(t_swap *s, int flag);
void	ft_sb(t_swap *s, int flag);
void	ft_ra(t_swap *s, int flag);
void	ft_rb(t_swap *s, int flag);
void	ft_rra(t_swap *s, int flag);
void	ft_rrb(t_swap *s, int flag);
void	ft_ss(t_swap *s, int flag);
void	ft_rrr(t_swap *s);
void	ft_rr(t_swap *s);
int		ft_atoi(char *str);
long	ft_atol(char *str);
int		is_digit(char *str);
void	ft_print(char *str);

int		ft_min(int *tab, int len);
int		ft_max(int *tab, int len);
void	ft_sort_3_numbers(t_swap *s);
int		is_sorted(int *tab, int size);
void	ft_print(char *str);
void	ft_sort_medium_stack(t_swap *s);
int		*new_stack(int *stack, int size);
void	ft_sort_medium_numbers(t_swap *s);
int		*ft_insert(int ac, char **av);
int		*ft_copy_stack_elements(t_swap *s);
int		check_digit(int ac, char **av);
int		find_midpoint(int *stack, int size);
void	ft_sort_int_tab(int *tab, int size);
void	ft_sort_big_stack_step_two(t_swap *s);
void	ft_sort_big_stack_step_three(t_swap *s);
void	ft_sort_medium_stack_step_two(t_swap *s);
void	ft_sort_medium_stack_step_one(t_swap *s);
int		ft_is_not_duplicate(int *stack, int size);
int		ft_check_int_min_max(int ac, char **av);
void	ft_assign(t_swap *s, int ac, char **av);
int		ft_create_midpoints(t_swap *s);
int		*push(int *stack, int element, int *old_stack, int size);
void	ft_send_number_to_top_stack_b(t_swap *s, int max, int index);
void	ft_send_number_to_top_stack_a(t_swap *s, int min, int index);
void	ft_sort_big_stack_step_one(t_swap *s);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(int size, char **strs, char *sep);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif