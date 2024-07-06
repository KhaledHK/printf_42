/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaled <khaled@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:10:12 by khkhaled          #+#    #+#             */
/*   Updated: 2024/06/21 00:00:15 by khaled           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_special(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
//switch case

int	print_special(va_list arg, char c)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_putint(va_arg(arg, int));
	else if (c == '%')
		count += ft_putchar(c);
	else if (c == 'x' || c == 'X')
		count += ft_print_hex(va_arg(arg, unsigned int), c);
	else if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'u')
		count += ft_putunsigned(va_arg(arg, unsigned int));
	else if (c == 'p')
		count += ft_print_ptr(va_arg(arg, unsigned long long));
	return (count);
}

//main
int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i + 1] != '\0' && format[i] == '%')
		{
			if (is_special(format[i + 1]))
			{
				i++;
				count += print_special(args, format[i]);
			}
			else
				count += ft_putchar(format[i]);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}

// // ////////////////
// int main() {
//     // Write C code here
//     // printf("  Try programiz.pro ---- %d ---",ft_putint(22));
// 	char *i;
// 	i = NULL;
// 	int l1, l2;
//        l1 = ft_printf("printm %s k  f %% \n",i);
// 	    l2=    printf("printf %s k  f %% \n",i);
// 		ft_printf("result ----l1 %d-------------------l2
//  %d------------- ",l1,l2);
//     return 0;
// }