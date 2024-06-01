/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeh <abeh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 04:35:17 by abeh              #+#    #+#             */
/*   Updated: 2024/06/02 02:11:20 by abeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int ft_printf(const char *placeholders,...);

int ft_print_percent();
int ft_print_char(int c);
int	ft_print_str(char *str);
int ft_print_nbr(int nb);
int ft_print_unsigned(unsigned int nb);
int	ft_print_hex(unsigned int num, const char format);


#endif