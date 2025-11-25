/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:25:40 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/25 11:34:17 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_arg(t_stack *stack)
{
	t_stack	*tmp;
	int		count;

	if (!stack)
		return (0);
	tmp = stack;
	count = 0;
	while (1)
	{
		count++;
		tmp = tmp->next;
		if (tmp == stack)
			break ;
	}
	return (count);
}

int	ft_atoi(char *argv, int *j, int *tmp)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	if (!argv[*j])
		return (-1);
	if (argv[*j] == '-' || argv[*j] == '+')
	{
		if (argv[*j] == '-')
			sign = -1;
		(*j)++;
	}
	while (argv[*j] >= '0' && argv[*j] <= '9')
	{
		number *= 10;
		number += argv[*j] - '0';
		(*j)++;
	}
	if (argv[*j] != '\0' && argv[*j] != ' ')
		return (-1);
	number *= sign;
	if (number > 2147483647 || number < -2147483648)
		return (-1);
	*tmp = (int)number;
	return (0);
}

void	ft_free_all(t_stack **stack_a, t_stack **stack_b, int error)
{
	t_stack	*tmp;
	t_stack	*head;

	if (error)
		write(2, "Error\n", 6);
	head = *stack_a;
	while (*stack_a)
	{
		tmp = (*stack_a)->next;
		free(*stack_a);
		if (tmp == head)
			break ;
		*stack_a = tmp;
	}
	head = *stack_b;
	while (*stack_b)
	{
		tmp = (*stack_b)->next;
		free(*stack_b);
		if (tmp == head)
			break ;
		*stack_b = tmp;
	}
	stack_a = NULL;
	stack_b = NULL;
}
