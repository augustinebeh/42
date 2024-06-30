/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:54:38 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 18:41:03 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	init_stack(stacks *s, int ac, char **av)
{
	s->a.data = malloc(sizeof(int) * (ac - 1));
	s->b.data = malloc(sizeof(int) * (ac - 1));
	int	i = 0;
	while (i < ac - 1)
	{
		if (!is_valid_int(av[i + 1]))
		{
			printf("Error, input '%s' is not a valid integer\n", av[i + 1]);
			free(s->a.data);
			free(s->b.data);
			exit(1);
		}
		s->a.data[i] = atoi(av[i + 1]);
		i++;
	}
	s->a.size = ac - 1;
	s->b.size = 0;
}

int	main(int ac, char **av)
{
	stacks s;

	init_stack(&s, ac, av);
	if (has_duplicates(&s))
		return (printf("Error DUPES!\n"));
	if (ac <= 4)
		swap_algo_three(&s);
	if (ac == 5)
		swap_algo_four(&s);
	return 0;
}
	// while (i < a.size && i < b.size)
	// {
	// 	if (a.data[i] < 10 && a.data[i] >= 0)
	// 		printf("%d    |  %d\n", a.data[i], b.data[i]);
	// 	else if ((a.data[i] < 100 && a.data[i] >= 10) || (a.data[i] < 0
	// 				&& a.data[i] > -10))
	// 		printf("%d   |  %d\n", a.data[i], b.data[i]);
	// 	else if ((a.data[i] < 1000 && a.data[i] >= 100) || (a.data[i] < 10
	// 				&& a.data[i] > -100))
	// 		printf("%d  |  %d\n", a.data[i], b.data[i]);
	// 	else if ((a.data[i] < 10000 && a.data[i] >= 1000) || (a.data[i] < 100
	// 				&& a.data[i] > -1000))
	// 		printf("%d |  %d\n", a.data[i], b.data[i]);
	// 	else if ((a.data[i] < 100000 && a.data[i] >= 10000)
	// 			|| (a.data[i] < 1000 && a.data[i] > -10000))
	// 		printf("%d|  %d\n", a.data[i], b.data[i]);
	// 	else
	// 		printf("%d |  %d\n", a.data[i], b.data[i]);
	// 	i++;
	// }
	// while (i < a.size)
	// {
	// 	if (a.data[i] < 10 && a.data[i] >= 0)
	// 		printf("%d    |\n", a.data[i]);
	// 	else if ((a.data[i] < 100 && a.data[i] >= 10) || (a.data[i] < 0
	// 				&& a.data[i] > -10))
	// 		printf("%d   |\n", a.data[i]);
	// 	else if ((a.data[i] < 1000 && a.data[i] >= 100) || (a.data[i] < 10
	// 				&& a.data[i] > -100))
	// 		printf("%d  |\n", a.data[i]);
	// 	else if ((a.data[i] < 10000 && a.data[i] >= 1000) || (a.data[i] < 100
	// 				&& a.data[i] > -1000))
	// 		printf("%d |\n", a.data[i]);
	// 	else if ((a.data[i] < 100000 && a.data[i] >= 10000)
	// 			|| (a.data[i] < 1000 && a.data[i] > -10000))
	// 		printf("%d|\n", a.data[i]);
	// 	else
	// 		printf("%d |\n", a.data[i]);
	// 	i++;
	// }
	// while (i < b.size)
	// {
	// 	printf("     |  %d\n", b.data[i]);
	// 	i++;
	// }




// VISUALIZER FOR CHECKING OF INSTRUCTIONS

// int	main(int ac, char **av)
// {
// 	int	*stack_a;
// 	int	*stack_b;
// 	int	i;
// 	int	ca;
// 	int	cb;

// 	stack_a = malloc(sizeof(int) * ac - 1);
// 	stack_b = malloc(sizeof(int) * ac - 1);
// 	i = 0;
// 	while (i < ac - 1)
// 	{
// 		stack_a[i] = atoi(av[i + 1]);
// 		i++;
// 	}
// 	ca = ac - 1;
// 	cb = 0;
// 	pb(stack_a, stack_b, &ca, &cb);
// 	pb(stack_a, stack_b, &ca, &cb);
// 	pb(stack_a, stack_b, &ca, &cb);
// 	pb(stack_a, stack_b, &ca, &cb);
// 	i = 0;
// 	printf("___________\n");
// 	printf("__A__|__B__\n");
// 	while (i < ca && i < cb)
// 	{
// 		if (stack_a[i] < 10 && stack_a[i] >= 0)
// 			printf("%d    |  %d\n", stack_a[i], stack_b[i]);
// 		else if ((stack_a[i] < 100 && stack_a[i] >= 10) || (stack_a[i] < 0
// 					&& stack_a[i] > -10))
// 			printf("%d   |  %d\n", stack_a[i], stack_b[i]);
// 		else if ((stack_a[i] < 1000 && stack_a[i] >= 100) || (stack_a[i] < 10
// 					&& stack_a[i] > -100))
// 			printf("%d  |  %d\n", stack_a[i], stack_b[i]);
// 		else if ((stack_a[i] < 10000 && stack_a[i] >= 1000) || (stack_a[i] < 100
// 					&& stack_a[i] > -1000))
// 			printf("%d |  %d\n", stack_a[i], stack_b[i]);
// 		else if ((stack_a[i] < 100000 && stack_a[i] >= 10000)
// 				|| (stack_a[i] < 1000 && stack_a[i] > -10000))
// 			printf("%d|  %d\n", stack_a[i], stack_b[i]);
// 		else
// 			printf("%d |  %d\n", stack_a[i], stack_b[i]);
// 		i++;
// 	}
// 	while (i < ca)
// 	{
// 		if (stack_a[i] < 10 && stack_a[i] >= 0)
// 			printf("%d    |\n", stack_a[i]);
// 		else if ((stack_a[i] < 100 && stack_a[i] >= 10) || (stack_a[i] < 0
// 					&& stack_a[i] > -10))
// 			printf("%d   |\n", stack_a[i]);
// 		else if ((stack_a[i] < 1000 && stack_a[i] >= 100) || (stack_a[i] < 10
// 					&& stack_a[i] > -100))
// 			printf("%d  |\n", stack_a[i]);
// 		else if ((stack_a[i] < 10000 && stack_a[i] >= 1000) || (stack_a[i] < 100
// 					&& stack_a[i] > -1000))
// 			printf("%d |\n", stack_a[i]);
// 		else if ((stack_a[i] < 100000 && stack_a[i] >= 10000)
// 				|| (stack_a[i] < 1000 && stack_a[i] > -10000))
// 			printf("%d|\n", stack_a[i]);
// 		else
// 			printf("%d |\n", stack_a[i]);
// 		i++;
// 	}
// 	while (i < cb)
// 	{
// 		printf("     |  %d\n", stack_b[i]);
// 		i++;
// 	}
// 	printf("\n");
// }
