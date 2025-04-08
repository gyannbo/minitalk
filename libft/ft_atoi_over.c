/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:20:06 by gbonis            #+#    #+#             */
/*   Updated: 2024/07/09 20:22:26 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char s)
{
	if ((s >= 9 && s <= 13) || s == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr, int *overflow)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	if (*nptr >= 48 && *nptr <= 57)
	{
		while (*nptr >= 48 && *nptr <= 57)
		{
			number = (number * 10) + *nptr - '0';
			nptr++;
		}
		number *= sign;
		return (number);
	}
	else
		return (0);
}
/*
int	main()
{
	char str[]= " -2983433,0x649";
	
	printf("%d\n", atoi(str));

	printf("%d\n", ft_atoi(str));
	return (0);
}
*/
