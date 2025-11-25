/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:20:00 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/25 17:18:18 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_how_far(t_stack **stack, int index_max)
{
	t_stack	*node;
	int		i;

	node = *stack;
	i = 0;
	while (node->index != index_max)
	{
		node = node->next;
		i++;
	}
	return (i);
}

static void	ft_algo_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int		index_max;

	index_max = ft_count_arg(*stack_b) - 1;
	while (*stack_b)
	{
		if (ft_how_far(stack_b, index_max) <= (index_max / 2))
		{
			while ((*stack_b)->index != index_max)
			{
				ft_operation(stack_a, stack_b, "rb");
			}
		}
		else
		{
			while ((*stack_b)->index != index_max)
			{
				ft_operation(stack_a, stack_b, "rrb");
			}
		}
		ft_operation(stack_a, stack_b, "pa");
		index_max--;
	}
}

void static	ft_algo_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	chunk;

	count = 0;
	chunk = 10 + ((ft_count_arg(*stack_a)) / 25);
	while (*stack_a)
	{
		if ((*stack_a)->index <= count)
		{
			ft_operation(stack_a, stack_b, "pb");
			ft_operation(stack_a, stack_b, "rb");
			count++;
		}
		else if ((*stack_a)->index <= count + chunk)
		{
			ft_operation(stack_a, stack_b, "pb");
			count++;
		}
		else
			ft_operation(stack_a, stack_b, "ra");
	}
}

void	ft_algo(t_stack **stack_a, t_stack **stack_b)
{
	ft_algo_stack_a(stack_a, stack_b);
	ft_algo_stack_b(stack_a, stack_b);
}
