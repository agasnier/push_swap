/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:20:00 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/25 11:43:47 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_algo_stack_a(t_stack **stack_a, t_stack **stack_b, int pos_bit)
{
	int		arg_in_a;
	t_stack	*node_a;

	arg_in_a = ft_count_arg(*stack_a);
	while (arg_in_a > 0)
	{
		node_a = *stack_a;
		if (node_a->index & (1 << pos_bit))
		{
			ft_operation(stack_a, stack_b, "ra");
			write(1, "ra\n", 3);
		}
		else
		{
			ft_operation(stack_a, stack_b, "pb");
			write(1, "pb\n", 3);
		}
		arg_in_a--;
	}
}

static void	ft_algo_stack_b(t_stack **stack_a, t_stack **stack_b, int pos_bit)
{
	pos_bit = 0;
	while (*stack_b)
	{
		ft_operation(stack_a, stack_b, "pa");
		write(1, "pa\n", 3);
	}
}

void	ft_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	arg_total;
	int	pos_bit;
	int	max_bit;

	arg_total = ft_count_arg(*stack_a);
	max_bit = 0;
	while (((arg_total - 1) >> max_bit) != 0)
		max_bit++;
	pos_bit = 0;
	while (pos_bit < max_bit)
	{
		if (!ft_verify_sorting(stack_a))
			break ;
		ft_algo_stack_a(stack_a, stack_b, pos_bit);
		ft_algo_stack_b(stack_a, stack_b, pos_bit);
		pos_bit++;
	}
}
