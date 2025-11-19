/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:24:35 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/19 12:54:04 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_create_end_node(t_stack **first_node, int content, int index)
{
	t_stack	*new_node;
	t_stack *node;


	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (1);

	new_node->content = content;
	new_node->index = index;
		
	
	if (*first_node == NULL)
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
		if (ft_atoi(argv[i], &tmp))
			return (-1);
		
		if (ft_create_end_node(stack_a, tmp, -1))
			return (-1);
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