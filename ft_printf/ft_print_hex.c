/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:21:52 by gbonis            #+#    #+#             */
/*   Updated: 2024/01/31 19:22:47 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_xtoa_len(unsigned long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num >= 1)
	{
		len++;
		num /= 16;
	}
	return (len);
}

char	*ft_hex_to_str(unsigned long int num, char *str, size_t len)
{
	int	mod;

	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	len--;
	while (len != (size_t)-1)
	{
		mod = num % 16;
		if (mod < 10)
			str[len] = mod + '0';
		else if (mod >= 10)
			str[len] = (mod - 10) + 'a';
		num = num / 16;
		len--;
	}
	return (str);
}

int	ft_print_hex(unsigned int num, int is_upper)
{
	size_t	len;
	char	*str;
	int		i;

	len = ft_xtoa_len(num);
	str = 0;
	str = ft_hex_to_str(num, str, len);
	if (!str)
		return (0);
	if (is_upper == 1)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] -= 32;
			i++;
		}
	}
	write(1, str, len);
	free(str);
	return (len);
}
