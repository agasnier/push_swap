/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:26:39 by algasnie          #+#    #+#             */
/*   Updated: 2025/12/04 16:17:26 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_search_index(t_stack **stack)
{
	t_stack	*node;
	t_stack	*node_tmp;
	int		count_arg;
	int		index;

	index = 0;
	count_arg = ft_count_arg(*stack);
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
				break ;
		}
		if (node_tmp != NULL)
			node_tmp->index = index;
		index++;
	}
}

int	ft_verif_dup(t_stack **stack)
{
	t_stack	*current;
	t_stack	*comp;

	current = *stack;
	while (1)
	{
		comp = current->next;
		while (comp != *stack)
		{
			if (comp->content == current->content)
				return (-1);
			comp = comp->next;
		}
		current = current->next;
		if (current == *stack)
			return (0);
	}
}

int	ft_verify_sorting(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (1)
	{
		if (node->content > node->next->content)
			return (-1);
		node = node->next;
		if (node->next == *stack)
			break ;
	}
	return (0);
}
