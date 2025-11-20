/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:25:40 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/20 13:17:36 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_arg(t_stack **stack)
{
	t_stack *tmp;
	int	count;
	
	if (!stack || !*stack)
		return (0);
	tmp = *stack;
	count = 0;
	while (1)
	{
		count++;
		tmp = tmp->next;
		if (tmp == *stack)
			break;
	}

	return (count);
}

int ft_atoi(char *argv, int *tmp)
{
	int	i;
	long number;
	int sign;

	i = 0;
	number = 0;
	sign = 1;
	if (argv[0] == '-' || argv[0] == '+')
	{
		if (argv[0] == '-')
			sign = -1;
		i++;
	}
	if (!argv[i])
		return (-1);
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (-1);
		number *= 10;
		number += argv[i] - '0';
		if (number > 2147483648)
			return (-1);
		i++;
	}
	number *= sign;
	if (number > 2147483647 || number < -2147483648)
		return (-1);
	*tmp = (int)number;
	return (0);
}

