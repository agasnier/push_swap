/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:26:39 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/20 10:34:41 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_search_index(t_stack **stack) //ajouter verif duplicata
{
	t_stack *node;
	t_stack	*node_tmp;
	int count_arg;
	int index;
	
	index = 0;
	count_arg = ft_count_arg(stack);
	
	while (index <= count_arg)
	{
		node = *stack;
		node_tmp = NULL;
		while (1)
		{
			if (node->index == -1)
				if (node_tmp == NULL || node_tmp->content > node->content)
					node_tmp = node;	
			node = node->next;
			if (node == *stack)
				break;
		}
		if (node_tmp != NULL)
			node_tmp->index = index;
		index++;
	}
}

#include <stdio.h>

int	ft_verify_sorting(t_stack **stack)
{
	t_stack *node_tmp;
	t_stack *node;

	node_tmp = *stack;
	node = *stack;
	
	while (1)
	{
		while (1)
		{
			if (node_tmp->content > node->content)
				return (-1);
			printf("tmp: %d %d :node\n", node_tmp->content, node->content);
			node = node->next;
			if (node == *stack)
				break;
		}
		node_tmp = node_tmp->next;
		if (node_tmp == *stack)
			break;
	}
	return (0);
}


