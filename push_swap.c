/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:41:38 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/25 11:28:51 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (ft_init_stack(&argv[1], &stack_a))
	{
		ft_free_all(&stack_a, &stack_b, 1);
		return (1);
	}
	if (ft_verif_dup(&stack_a))
	{
		ft_free_all(&stack_a, &stack_b, 1);
		return (1);
	}
	ft_search_index(&stack_a);
	ft_algo(&stack_a, &stack_b);
	ft_free_all(&stack_a, &stack_b, 0);
	return (0);
}
