/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:16:44 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/19 12:54:44 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

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
int		ft_create_end_node(t_stack **first_node, int content, int index);
int		ft_init_stack(char **argv, t_stack **stack_a);
t_stack	**ft_create_stack(t_stack **stack);

//ft_verification.c
void	ft_search_index(t_stack **stack);

//ft_helper.c
int		ft_atoi(char *argv, int *tmp);
int		ft_count_arg(t_stack **stack);


#endif