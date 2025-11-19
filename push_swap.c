/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:41:38 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/19 12:57:40 by algasnie         ###   ########.fr       */
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
		if (test == *stack_a)
			break;
	}
	//////////////////////////////////////////////////////////////////////


	//fonction du sujet
	





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
		if (test == *stack_a)
			break;
	}
	//////////////////////////////////////////////////////////////////////

	//en binaire si 0 stack a / si 1 stack b

	


	return (0);
}