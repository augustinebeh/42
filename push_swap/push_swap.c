/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:54:38 by abeh              #+#    #+#             */
/*   Updated: 2024/06/30 03:50:27 by abeh             ###   ########.fr       */
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

	pa(stack_a,stack_b, &ca, &cb);
	pa(stack_a,stack_b, &ca, &cb);
	pb(stack_a,stack_b, &ca, &cb);
	pb(stack_a,stack_b, &ca, &cb);
	// pb(stack_a,stack_b, &ca, &cb);
	// ra(stack_a,stack_b, &ca, &cb);
	rb(stack_a,stack_b, &ca, &cb);

	// printf("value of ca is %d, value of cb is %d\n", ca,cb);
	// rra(stack_a,stack_b, &ca, &cb);
	rrb(stack_a,stack_b, &ca, &cb);
	// pb(stack_a,stack_b, &ca, &cb);
	// pb(stack_a,stack_b, &ca, &cb);
	// pb(stack_a,stack_b, &ca, &cb);

	// printf("value of ca is %d, value of cb is %d\n", ca,cb);

	i = 0;
	while (i < ca)
	{
		printf("line %d of stack_a is: %d\n", i + 1, stack_a[i]);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < cb)
	{
		printf("line %d of stack_b is: %d\n", i + 1, stack_b[i]);
		i++;
	}
}
