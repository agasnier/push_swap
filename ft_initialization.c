/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:24:35 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/24 16:20:46 by algasnie         ###   ########.fr       */
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
	int j;
	int	tmp;

	i = 0;
		while (argv[i])
	{
		j = 0;
		if (!argv[i][j])
			return (-1);
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				j++;
			if (ft_atoi(argv[i], &j, &tmp))
				return (-1);
			if (ft_create_end_node(stack_a, tmp, -1))
				return (-1);
		}
		i++;
	}
	return (0);
}