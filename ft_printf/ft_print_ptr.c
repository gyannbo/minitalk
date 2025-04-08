/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:00:40 by gbonis            #+#    #+#             */
/*   Updated: 2024/01/31 19:04:14 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long int num)
{
	int		count;
	size_t	len_num;
	char	*str;

	str = 0;
	count = 0;
	if (num == 0)
	{
		count = ft_print_str("(nil)");
		return (count);
	}
	count += ft_print_str("0x");
	len_num = ft_xtoa_len(num);
	str = ft_hex_to_str(num, str, len_num);
	ft_print_str(str);
	free(str);
	count += len_num;
	return (count);
}

//
//int	main ()
//{
//	unsigned long int nul = 0;
//	unsigned long int *zer;
//	zer = (unsigned long int *)nul;
//	int count;
//
//	count = ft_print_ptr((unsigned long int)zer);
//	printf("%d\n", count);
//	count = printf("%p", zer);
//	printf("%d\n", count);
//
//	int a;
//	int *ptr;
//
//	a = 123;
//	ptr = &a;
//	
//	printf("\n\n--------------------------------\n\n");
//	count = ft_printf("%p\n", ptr);
//	printf("%d\n", count);
//	count = printf("%p\n", ptr);
//	printf("%d\n", count);
//	return (0);
//
//
//}
