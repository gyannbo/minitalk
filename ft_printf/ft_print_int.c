/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:23:42 by gbonis            #+#    #+#             */
/*   Updated: 2024/01/31 19:02:02 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_print_int(long unsigned int x)
{
	long unsigned int	count;
	char				*str;

	str = ft_itoa(x);
	count = ft_strlen(str);
	write(1, str, count);
	free(str);
	return (count);
}

static int	get_digits(long n)
{
	int	i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		digits;
	long int	num;

	num = n;
	digits = get_digits(n);
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (!(str_num))
		return (NULL);
	*(str_num + digits) = 0;
	while (digits--)
	{
		*(str_num + digits) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*str_num = '-';
	return (str_num);
}
// test count 
// 
//int	main()
//{
//	int x = -1234;
//	int count;
//	
//	count = ft_print_int(x);
//	printf("\n%d\n", count);
//	count = printf("%d", x);
//	printf("\n");
//	printf("%d\n", count);
//	return (0);
//}
//
//
