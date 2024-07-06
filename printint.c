/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prntint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkhaled <khkhaled@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 06:52:35 by khkhaled          #+#    #+#             */
/*   Updated: 2024-06-21 06:52:35 by khkhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	positif_print(int a)
{
	int	count;

	count = 0;
	if (a / 10 == 0)
	{
		count += ft_putchar(a + '0');
	}
	else
	{
		count += positif_print(a / 10);
		count += ft_putchar((a % 10) + '0');
	}
	return (count);
}

int	ft_putint(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putchar('-');
		count += ft_putchar('2');
		n = 147483648;
	}
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		count += positif_print(-n);
	}
	else
		count += positif_print(n);
	return (count);
}
