/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:10:11 by gbonis            #+#    #+#             */
/*   Updated: 2024/01/31 19:03:49 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

static size_t	ft_utoa_len(long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		len++;
		num /= 10;
	}
	return (len);
}

static char	*ft_u_to_str(unsigned int num, char *str, size_t len)
{
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	len--;
	while (len)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	str[0] = (num % 10) + '0';
	return (str);
}

int	ft_print_unsigned(unsigned int num)
{
	size_t	len;
	char	*str;

	len = ft_utoa_len(num);
	str = 0;
	str = ft_u_to_str(num, str, len);
	if (!str)
		return (0);
	write (1, str, len);
	free(str);
	return (len);
}
