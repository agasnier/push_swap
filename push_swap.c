/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algasnie <algasnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 14:41:38 by algasnie          #+#    #+#             */
/*   Updated: 2025/11/17 17:41:11 by algasnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "push_swap.h"


char *ft_atoi(char *argv)
{



	
}

int	ft_create_end_node(char **argv)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	
	//creer une node

	//la mettre a la fin
		//la fin de la boucle c'est le moment où (*t_stack** == t_stack*) - 1


	
	



}

int	ft_init_stack(char **argv, t_stack **stack_a)
{
	int	tmp;



	//boucle pour chaque arg
		//remplir le tmp avoir le nombre char en int (error: !int & int min max)
			//if nbr > int min int max / 10 return 1

		//verifier si duplicata

		//create end node
			//creer une node (int + ->next)
			//add_back

	//fin boucle
}



int	main(int argc, char **argv)
{
	int	i;
	
	printf("Nombres d'arguments: %d\n", argc);

	i = 1;
	while (i < argc)
	{
		printf("Arguments %d: %s\n", argc, argv[i]);
		i++;
	}


	t_stack	**stack_a;
	t_stack **stack_b;

	stack_a = malloc(sizeof(t_stack *));
	if (!stack_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	
	stack_b = malloc(sizeof(t_stack *));
	if (!stack_b)
	{
		write(2, "Error\n", 6);
		return (1);
	}

	//creer une liste chainée bouclée / remplir des argv / parsing (error)
	if (ft_init_stack(argv, stack_a))
	{
		write(2, "Error\n", 6);
		return (1);
	}




	//en binaire si 0 stack a / si 1 stack b

	


	return (0);
}