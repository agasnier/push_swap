/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:44 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/24 15:51:30 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>


#include <stdio.h>

typedef struct s_stack
{
	int content;
	int	index;
	struct s_stack *next;
	struct s_stack *prev;
}	t_stack;

//push_swap.c
int		main(int argc, char **argv);

//ft_initialization.c
int		ft_create_end_node(t_stack *first_node, int content, int index);
int		ft_init_stack(char **argv, t_stack *stack_a);

//ft_verification.c
void	ft_search_index(t_stack *stack);
int		ft_verify_sorting(t_stack *stack);

//ft_helper.c
int		ft_atoi(char *argv, int *j, int *tmp);
int		ft_count_arg(t_stack *stack);
void	ft_free_all(t_stack *stack_a, t_stack *stack_b);

//ft_operation.c
void ft_operation(t_stack *stack_a, t_stack *stack_b, char *op);


#endif