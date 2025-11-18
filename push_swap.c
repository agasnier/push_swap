/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:41:38 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/18 19:16:04 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>


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
		return (1);
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (1);
		number *= 10;
		number += argv[i] - '0';
		if (number > 2147483648)
			return (1);
		i++;
	}
	number *= sign;
	if (number > 2147483647 || number < -2147483648)
		return (1);
	*tmp = (int)number;
	return (0);
}

int	ft_create_end_node(t_stack **first_node, int content)
{
	t_stack	*new_node;
	t_stack *node;


	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (1);

	new_node->content = content;
		
	
	if (*first_node == NULL) // ok avec printf
	{
		*first_node = new_node;
		new_node->next = *first_node;
		new_node->prev = *first_node;
	}
	else
	{
		node = (*first_node)->prev;
		node->next = new_node;
		new_node->prev = node;
		new_node->next = *first_node;
		(*first_node)->prev = new_node;
	}
	return (0);
}

int	ft_init_stack(char **argv, t_stack **stack_a)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (argv[i])
	{
		if (ft_atoi(argv[i], &tmp)) ////gestion erreur
			return (1);
			
		//verifier si duplicata
		
		if (ft_create_end_node(stack_a, tmp))
			return (1);
			
		i++;
	}
	return (0);
}

t_stack	**ft_create_stack(t_stack **stack)
{
	stack = malloc(sizeof(t_stack *));
	if (!stack)
		return (NULL);
	*stack = NULL;
	return (stack);
}


int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack **stack_b;

	if (argc <= 1)
		return (0);

	
	////////////////Creation des deux stacks///////////////////////
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_create_stack(stack_a);
	stack_b = ft_create_stack(stack_b);
	if (!stack_a || !stack_b)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	///////////////////////////////////////////////////////////////



	
	//creation liste chainee avec les arguments et gestions d'erreur
	if (ft_init_stack(&argv[1], stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}

	//////////////////////// test stack_a/////////////////////////// 
	t_stack *test_first;
	test_first = *stack_a;
	
	printf("first node: %10p\t node: %10p\t content: %10d\t next: %10p\t previous: %10p\n", *stack_a, test_first, test_first->content, test_first->next, test_first->prev);
	while (test_first->next != *stack_a)
	{
		test_first = test_first->next;
		printf("first node: %10p\t node: %10p\t content: %10d\t next: %10p\t previous: %10p\n", *stack_a, test_first, test_first->content, test_first->next, test_first->prev);
	}
	//////////////////////////////////////////////////////////////////////


	//indexation 

	//fonction du sujet

	//en binaire si 0 stack a / si 1 stack b

	


	return (0);
}