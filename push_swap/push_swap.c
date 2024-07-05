/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 23:54:38 by abeh              #+#    #+#             */
/*   Updated: 2024/07/06 04:44:19 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_errors_and_allocate(t_stacks *s, int ac, char **av)
{
	int		i;
	long	o;

	s->a.element = malloc(sizeof(t_elements) * (ac - 1));
	s->b.element = malloc(sizeof(t_elements) * (ac - 1));
	if (!s->a.element || !s->b.element)
	{
		free(s->a.element);
		free(s->b.element);
		exit(1);
	}
	i = 0;
	while (i < ac - 1)
	{
		o = ft_atol(av[i + 1]);
		if (!is_valid_int(av[i + 1]) || o > INT_MAX || o < INT_MIN)
		{
			ft_printf("Error\n");
			free(s->a.element);
			free(s->b.element);
			exit(1);
		}
		i++;
	}
}

void	init_stack(t_stacks *s, int ac, char **av)
{
	int	i;

	check_errors_and_allocate(s, ac, av);
	i = 0;
	while (i < ac - 1)
	{
		s->a.element[i].data = ft_atol(av[i + 1]);
		i++;
	}
	index_elements(s->a.element, ac - 1);
	append_bits(s->a.element, ac - 1);
	s->a.size = ac - 1;
	s->b.size = 0;
	if (has_duplicates(s))
	{
		ft_printf("Error\n");
		free(s->a.element);
		free(s->b.element);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_stacks	s;

	if (ac == 1)
		return (0);
	init_stack(&s, ac, av);
	if (is_sorted(&s))
	{
		free(s.a.element);
		free(s.b.element);
		return (0);
	}
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
}
