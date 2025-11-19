/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:26:39 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/19 12:55:27 by algasnie         ###   ########.fr       */
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