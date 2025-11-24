/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:41:38 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/24 15:58:02 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "push_swap.h"




	////////////////////////function print stack

void	print_s(t_stack **stack)
	{
		t_stack *node = *stack;

		while (node)
		{
			printf("c: %10d\n", node->content);
			node = node->next;
			if (node == *stack)
				break;
		}
		printf("\n");
	}
	




int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;


	if (argc <= 1)
		return (0);

	stack_a = NULL;
	stack_b = NULL;
	
	if (ft_init_stack(&argv[1], stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}

	printf("count arg \n");
	
	ft_search_index(stack_a); //ajouter verif duplicata
	
	int arg_total;
	int arg_in_a;
	t_stack *node_a;
	int pos_bit;
	int max_bit;

	arg_total = ft_count_arg(stack_a);
	max_bit = 0;
	while (((arg_total - 1) >> max_bit) != 0)
		max_bit++;

	pos_bit = 0;
	while (pos_bit < max_bit)
	{		
		if (!ft_verify_sorting(stack_a))
			break;
			
		arg_in_a = ft_count_arg(stack_a);
		
		while (arg_in_a > 0)
		{
			node_a = stack_a;
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

			//////
			// printf("\n stack_a\n");
			// print_s(stack_a);
			// printf("\n stack_b\n");
			// print_s(stack_b);
			// printf("\n");
			/////
		}

		while (stack_b)
		{
			ft_operation(stack_a, stack_b, "pa");
			write(1, "pa\n", 3);
		}
		pos_bit++;
	}

	// printf("\n\n\n stack_a final\n");
	// print_s(&stack_a);

	ft_free_all(stack_a, stack_b);



	return (0);
}