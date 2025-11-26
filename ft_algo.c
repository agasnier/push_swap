/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:20:00 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/26 13:16:20 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	ft_algo_stack_a(t_stack **stack_a, t_stack **stack_b)
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

static void	ft_algo_three(t_stack **stack_a, t_stack **stack_b,
	int nb_arg, int index)
{
	if (nb_arg == 4 || nb_arg == 5)
	{
		if (ft_how_far(stack_a, index) > nb_arg / 2)
			while ((*stack_a)->index != index)
				ft_operation(stack_a, stack_b, "rra");
		else
			while ((*stack_a)->index != index)
				ft_operation(stack_a, stack_b, "ra");
		ft_operation(stack_a, stack_b, "pb");
		if (nb_arg == 5)
			ft_algo_three(stack_a, stack_b, nb_arg - 1, 1);
		else
			ft_algo_three(stack_a, stack_b, nb_arg - 1, 0);
		ft_operation(stack_a, stack_b, "pa");
	}
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		ft_operation(stack_a, stack_b, "ra");
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
		ft_operation(stack_a, stack_b, "rra");
	if (ft_verify_sorting(stack_a))
		ft_operation(stack_a, stack_b, "sa");
}

void	ft_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	nb_arg;

	nb_arg = ft_count_arg(*stack_a);
	if (ft_verify_sorting(stack_a))
	{
		if (nb_arg == 2)
			ft_operation(stack_a, stack_b, "ra");
		else if (nb_arg >= 3 && nb_arg <= 5)
			ft_algo_three(stack_a, stack_b, nb_arg, 0);
		else
		{
			ft_algo_stack_a(stack_a, stack_b);
			ft_algo_stack_b(stack_a, stack_b);
		}
	}
}
