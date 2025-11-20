/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:41:38 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/20 13:35:22 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "push_swap.h"





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



	
	//creation liste chainee avec les arguments et gestions d'erreur + retourne nbr arg
	
	if (ft_init_stack(&argv[1], stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	
	ft_search_index(stack_a); //ajouter verif duplicata



	
	//////////////////////// test stack_a && stack_b/////////////////////////// 
	t_stack *test;
	
	test = *stack_a;
	printf("\n\nstack_a\n");
	while (test)
	{
		printf("first node: %10p\t node: %10p\t content: %10d\t index: %10d\t next: %10p\t previous: %10p\n", *stack_a, test, test->content, test->index, test->next, test->prev);
		test = test->next;
		if (test == *stack_a)
			break;
	}

	test = *stack_b;
	printf("\nstack_b\n\n");
	while (test)
	{
		printf("first node: %10p\t node: %10p\t content: %10d\t index: %10d\t next: %10p\t previous: %10p\n", *stack_a, test, test->content, test->index, test->next, test->prev);
		test = test->next;
		if (test == *stack_b)
			break;
	}
	//////////////////////////////////////////////////////////////////////
	
	
	int arg_total;
	int arg_in_a;
	// int arg_in_b;
	t_stack *node_a;
	int pos_bit;
	int max_bit;

	arg_total = ft_count_arg(stack_a);
	printf("arg total: %d\n\n", arg_total);
	printf("verify sorting: %d\n\n", ft_verify_sorting(stack_a));
	
	
	max_bit = 0;
	while (((arg_total - 1) >> max_bit) != 0)
		max_bit++;

	pos_bit = 0;
	while (pos_bit < max_bit)
	{
		printf("boucle\n");
		
		if (!ft_verify_sorting(stack_a))
			break;
			
		arg_in_a = ft_count_arg(stack_a);
		
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

		while (*stack_b)
		{
			ft_operation(stack_a, stack_b, "pa");
			printf("test %d\n", ft_count_arg(stack_b));
		}
		pos_bit++;
	}


	//////////////////////// test stack_a && stack_b/////////////////////////// 
	
	test = *stack_a;
	printf("\n\nstack_a\n");
	while (test)
	{
		printf("first node: %10p\t node: %10p\t content: %10d\t index: %10d\t next: %10p\t previous: %10p\n", *stack_a, test, test->content, test->index, test->next, test->prev);
		test = test->next;
		if (test == *stack_a)
			break;
	}

	test = *stack_b;
	printf("\nstack_b\n\n");
	while (test)
	{
		printf("first node: %10p\t node: %10p\t content: %10d\t index: %10d\t next: %10p\t previous: %10p\n", *stack_a, test, test->content, test->index, test->next, test->prev);
		test = test->next;
		if (test == *stack_b)
			break;
	}
	//////////////////////////////////////////////////////////////////////


	


	return (0);
}