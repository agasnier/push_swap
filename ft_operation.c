/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:04:26 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/24 16:22:41 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	first = *stack;
	second = (*stack)->next;

	first->next = second->next;
	first->next->prev = first;
	second->prev = first->prev;
	second->prev->next = second;

	first->prev = second;
	second->next = first;
	*stack = second;
}

void ft_push(t_stack **receiver, t_stack **sender)
{
	t_stack *node;

	if (!sender || !*sender)
        return;
	
	node = *sender;
	if (node->next == node)
		*sender = NULL;
	else
	{
		*sender = (*sender)->next;
		(*sender)->prev = node->prev;
		node->prev->next = *sender;
	}

	if (!*receiver)
	{
		*receiver = node;
		node->next = node;
		node->prev =node;
	}
	else
	{
		node->prev = (*receiver)->prev;
		node->next = *receiver;
		(*receiver)->prev->next = node;
		(*receiver)->prev = node;
		*receiver = node;
	}
}

void ft_rotate(t_stack **stack, int reverse)
{
	if (!reverse)
		*stack = (*stack)->next;
	else
		*stack = (*stack)->prev;
}



void ft_operation(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (*stack_a && op[0] == 's' && op[1] == 'a')
		ft_swap(stack_a);
	else if (*stack_b && op[0] == 's' && op[1] == 'b')
		ft_swap(stack_b);
	else if (op[0] == 's' && op[1] == 's')
	{
		ft_operation(stack_a, stack_b, "sa");
		ft_operation(stack_a, stack_b, "sb");
	}

	else if (*stack_b && op[0] == 'p' && op[1] == 'a')
		ft_push(stack_a, stack_b);
	else if (*stack_a && op[0] == 'p' && op[1] == 'b')
		ft_push(stack_b, stack_a);

	else if (*stack_a && op[0] == 'r' && op[1] == 'a' && !op[2])
		ft_rotate(stack_a, 0);
	else if (*stack_b && op[0] == 'r' && op[1] == 'b' && !op[2])
		ft_rotate(stack_b, 0);
	else if (op[0] == 'r' && op[1] == 'r' && !op[2])
	{
		ft_rotate(stack_a, 0);
		ft_rotate(stack_b, 0);
	}

	else if (*stack_a && op[0] == 'r' && op[1] == 'r' && op[2] == 'a')
		ft_rotate(stack_a, 1);
	else if (*stack_a && op[0] == 'r' && op[1] == 'r' && op[2] == 'b')
		ft_rotate(stack_b, 1);
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == 'r')
	{
		ft_rotate(stack_a, 1);
		ft_rotate(stack_b, 1);
	}
}