/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:54:38 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 04:16:01 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int main(int ac, char **av)
{
	int *stack_a;
	int *stack_b;
	int i;
	int ca;
	int cb;

	stack_a = malloc(sizeof(int) * ac-1);
	stack_b = malloc(sizeof(int) * ac-1);
	i = 0;
	while (i < ac - 1)
	{
		stack_a[i] = atoi(av[i + 1]);
		i++;
	}
	ca = ac - 1;
	cb = 0;
	// printf("value of ca is %d, value of cb is %d\n", ca,cb);

	pb(stack_a,stack_b, &ca, &cb);
	pb(stack_a,stack_b, &ca, &cb);
	pb(stack_a,stack_b, &ca, &cb);
	pb(stack_a,stack_b, &ca, &cb);
	// pb(stack_a,stack_b, &ca, &cb);
	// pb(stack_a,stack_b, &ca, &cb);
	// pb(stack_a,stack_b, &ca, &cb);
	// ra(stack_a,stack_b, &ca, &cb);
	// rb(stack_a,stack_b, &ca, &cb);

	// printf("value of ca is %d, value of cb is %d\n", ca,cb);
	// rra(stack_a,stack_b, &ca, &cb);
	// rrb(stack_a,stack_b, &ca, &cb);
	// pb(stack_a,stack_b, &ca, &cb);
	// pb(stack_a,stack_b, &ca, &cb);
	// pb(stack_a,stack_b, &ca, &cb);

	// printf("value of ca is %d, value of cb is %d\n", ca,cb);

	i = 0;
	printf("___________\n");
	printf("__A__|__B__\n");
	while (i < ca && i < cb)
	{
		if (stack_a[i] < 10 && stack_a[i] >= 0)
			printf("%d    |  %d\n", stack_a[i], stack_b[i]);
		else if ((stack_a[i] < 100 && stack_a[i] >= 10) || (stack_a[i] < 0 && stack_a[i] > -10))
			printf("%d   |  %d\n", stack_a[i], stack_b[i]);
		else if ((stack_a[i] < 1000 && stack_a[i] >= 100) || (stack_a[i] < 10 && stack_a[i] > -100))
			printf("%d  |  %d\n", stack_a[i], stack_b[i]);
		else if ((stack_a[i] < 10000 && stack_a[i] >= 1000) || (stack_a[i] < 100 && stack_a[i] > -1000))
			printf("%d |  %d\n", stack_a[i], stack_b[i]);
		else if ((stack_a[i] < 100000 && stack_a[i] >= 10000) || (stack_a[i] < 1000 && stack_a[i] > -10000))
			printf("%d|  %d\n", stack_a[i], stack_b[i]);
		else
			printf("%d |  %d\n", stack_a[i], stack_b[i]);
		i++;
	}
	while (i < ca)
	{
		if (stack_a[i] < 10 && stack_a[i] >= 0)
			printf("%d    |\n", stack_a[i]);
		else if ((stack_a[i] < 100 && stack_a[i] >= 10) || (stack_a[i] < 0 && stack_a[i] > -10))
			printf("%d   |\n", stack_a[i]);
		else if ((stack_a[i] < 1000 && stack_a[i] >= 100) || (stack_a[i] < 10 && stack_a[i] > -100))
			printf("%d  |\n", stack_a[i]);
		else if ((stack_a[i] < 10000 && stack_a[i] >= 1000) || (stack_a[i] < 100 && stack_a[i] > -1000))
			printf("%d |\n", stack_a[i]);
		else if ((stack_a[i] < 100000 && stack_a[i] >= 10000) || (stack_a[i] < 1000 && stack_a[i] > -10000))
			printf("%d|\n", stack_a[i]);
		else
			printf("%d |\n", stack_a[i]);
		i++;
	}
	while (i < cb)
	{
		printf("     |  %d\n", stack_b[i]);
		i++;
	}
	printf("\n");
}
