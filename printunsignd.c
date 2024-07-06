/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsignd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkhaled <khkhaled@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 06:57:07 by khkhaled          #+#    #+#             */
/*   Updated: 2024-06-21 06:57:07 by khkhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	positif_print_unsigned(unsigned int a)
{
	int	count;

	count = 0;
	if (a / 10 == 0)
	{
		count += ft_putchar(a + '0');
	}
	else
	{
		count += positif_print_unsigned(a / 10);
		count += ft_putchar((a % 10) + '0');
	}
	return (count);
}

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	count += positif_print_unsigned(n);
	return (count);
}
