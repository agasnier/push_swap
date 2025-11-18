/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:41:38 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/18 13:44:58 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>


int ft_atoi(char *argv)
{
	int	i;
	int sign;
	int	number;

	i = 0;
	number = 0;
	sign = 1;
	if (argv[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (argv[0] == '+')
		i++;
	while (argv[i])
	{
		if (number > INT_MAX / 10 || (argv[i] < '0' || argv[i] > '9'))
			return (123); ////////////////////////////////////////////////////////////////////// a ;odifie
		number *= 10;
		number += argv[i] - '0';
		i++;
	}
	number *= sign;
	return (number);
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
		new_node->next = NULL;
		return (0);
	}
	
	node = *first_node;
	
	while (node->next != NULL && node->next != *first_node)
	 	node = node->next;
	node->next = new_node;
	new_node->next = *first_node;
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
		tmp = ft_atoi(argv[i]); ////gestion erreur
		if (tmp == 123)
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
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	stack = NULL;
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
	///////////////////////////////////////////////////////////////



	
	//creation liste chainee avec les arguments et gestions d'erreur
	if (ft_init_stack(&argv[1], stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}

	//////////////////////// test stack_a/////////////////////////// 
	// t_stack *test_first;
	// test_first = *stack_a;
	
	// printf("first node: %p, node: %p, content: %d, next: %p\n", *stack_a, test_first, test_first->content, test_first->next);
	// while (test_first->next != NULL && test_first->next != *stack_a)
	// {
	// 	test_first = test_first->next;
	// 	printf("first node: %p, node: %p, content: %d, next: %p\n", *stack_a, test_first, test_first->content, test_first->next);
	// }
	//////////////////////////////////////////////////////////////////////


	//en binaire si 0 stack a / si 1 stack b

	


	return (0);
}