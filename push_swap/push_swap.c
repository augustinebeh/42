/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:54:38 by abeh              #+#    #+#             */
/*   Updated: 2024/07/02 08:12:10 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(stacks *s, int ac, char **av)
{
	s->a.element = malloc(sizeof(elements) * (ac - 1));
	s->b.element = malloc(sizeof(elements) * (ac - 1));
	int	i = 0;
	while (i < ac - 1)
	{
		if (!is_valid_int(av[i + 1]))
		{
			printf("Error\n");
			free(s->a.element);
			free(s->b.element);
			exit(1);
		}
		s->a.element[i].data = atoi(av[i + 1]);
		i++;
	}
	index_elements(s->a.element, ac - 1);
	append_bits(s->a.element, ac - 1);
	s->a.size = ac - 1;
	s->b.size = 0;
}

int	main(int ac, char **av)
{
	stacks s;

	init_stack(&s, ac, av);
	if (has_duplicates(&s))
		return (printf("Error\n"));
	else if (is_sorted(&s))
   	return 0;
	else if (ac <= 4)
		swap_algo_three(&s);
	else if (ac <= 6)
		swap_algo_five(&s);
	else
		major_algo(&s);
	if (s.a.element)
		free(s.a.element);
	if (s.b.element)
		free(s.b.element);

	return (0);



	// int i = 0;
	// printf("size of a = %d\n", s.a.size);
	// printf("___________\n");
	// printf("__A__|__B__\n");

	// while (i < s.a.size && i < s.b.size)
	// {
	// 	if (s.a.element[i].data < 10 && s.a.element[i].data >= 0)
	// 		printf("%d %d     |  %d %d\n", s.a.element[i].data, s.a.element[i].index, s.b.element[i].data, s.b.element[i].index);
	// 	else if ((s.a.element[i].data < 100 && s.a.element[i].data >= 10) || (s.a.element[i].data < 0 && s.a.element[i].data > -10))
	// 		printf("%d %d    |  %d %d\n", s.a.element[i].data, s.a.element[i].index, s.b.element[i].data, s.b.element[i].index);
	// 	else if ((s.a.element[i].data < 1000 && s.a.element[i].data >= 100) || (s.a.element[i].data < 10 && s.a.element[i].data > -100))
	// 		printf("%d %d   |  %d %d\n", s.a.element[i].data, s.a.element[i].index, s.b.element[i].data, s.b.element[i].index);
	// 	else if ((s.a.element[i].data < 10000 && s.a.element[i].data >= 1000) || (s.a.element[i].data < 100 && s.a.element[i].data > -1000))
	// 		printf("%d %d  |  %d %d\n", s.a.element[i].data, s.a.element[i].index, s.b.element[i].data, s.b.element[i].index);
	// 	else if ((s.a.element[i].data < 100000 && s.a.element[i].data >= 10000) || (s.a.element[i].data < 1000 && s.a.element[i].data > -10000))
	// 		printf("%d %d |  %d %d\n", s.a.element[i].data, s.a.element[i].index, s.b.element[i].data, s.b.element[i].index);
	// 	else
	// 		printf("%d %d |  %d %d\n", s.a.element[i].data, s.a.element[i].index, s.b.element[i].data, s.b.element[i].index);
	// 	i++;
	// }
	//  while (i < s.a.size)
   //  {
	// 	if (s.a.element[i].data < 10 && s.a.element[i].data >= 0)
	// 		printf("%d %d     |\n", s.a.element[i].data, s.a.element[i].index);
	// 	else if ((s.a.element[i].data < 100 && s.a.element[i].data >= 10) || (s.a.element[i].data < 0 && s.a.element[i].data > -10))
	// 		printf("%d %d    |\n", s.a.element[i].data, s.a.element[i].index);
	// 	else if ((s.a.element[i].data < 1000 && s.a.element[i].data >= 100) || (s.a.element[i].data < 10 && s.a.element[i].data > -100))
	// 		printf("%d %d   |\n", s.a.element[i].data, s.a.element[i].index);
	// 	else if ((s.a.element[i].data < 10000 && s.a.element[i].data >= 1000) || (s.a.element[i].data < 100 && s.a.element[i].data > -1000))
	// 		printf("%d %d  |\n", s.a.element[i].data, s.a.element[i].index);
	// 	else if ((s.a.element[i].data < 10000 && s.a.element[i].data >= 1000) || (s.a.element[i].data < 100 && s.a.element[i].data > -1000))
	// 		printf("%d %d |\n", s.a.element[i].data, s.a.element[i].index);
	// 	else
	// 		printf("%d %d |\n", s.a.element[i].data, s.a.element[i].index);
	// 	i++;
	// }
	// while (i < s.b.size)
	// {
	// 	printf("     |  %d %d\n", s.b.element[i].data, s.b.element[i].index);
	// 	i++;
	// }
}




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
