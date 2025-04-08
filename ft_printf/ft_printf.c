/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:34:37 by gbonis            #+#    #+#             */
/*   Updated: 2024/02/01 18:42:00 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"

int	ft_print_arg(char type, va_list args)
{
	int	count;

	count = 0;
	if (type == '%')
		count += ft_print_char('%');
	else if (type == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (type == 's')
		count += ft_print_str(va_arg(args, const char *));
	else if (type == 'd' || type == 'i')
		count += ft_print_int(va_arg(args, int));
	else if (type == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (type == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (type == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (type == 'p')
		count += ft_print_ptr((unsigned long int)va_arg(args, void *));
	return (count);
}

int	ft_parse(char *str, va_list args)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			if (str[i] != '\0' && ft_istype(str[i]))
				count += ft_print_arg(str[i], args);
			else if (str[i] != '\0')
				count += ft_print_char(str[i]);
		}
		else
			count += ft_print_char(str[i]);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	char		*str;

	if (!format || *format == '\0')
		return (0);
	str = ft_strdup(format);
	if (!str || *str == '\0')
		return (0);
	count = 0;
	va_start(args, format);
	count = ft_parse(str, args);
	va_end(args);
	free(str);
	return (count);
}

//int	main()
//{
//	//variable test count + template
//
//
//	int count_ft;
//	int count_real;
//	char *lines = "\n---------------------------------------------------\n\n";
//	printf("%s", lines);
//
//	//test char
//	printf("test char\n\n");
//	char *s = "allobonjour";
//	count_ft = ft_printf("%s\n%%\n", s);
//	count_real = printf("%s\n%%\n", s);
//	printf("%d\n%d\n%s", count_ft, count_real, lines);
//
//	//test int with  d flag
//	printf("test int with d flag\n\n");
//	int a = -2147483648 ;
//	int b = 0;
//	int c = 2147483647;
//	count_ft = ft_printf("%d\n%d\n%d\n\n", a, b, c);
//	count_real = printf("%d\n%d\n%d\n\n", a, b, c);
//	printf("%d\n%d\n%s", count_ft, count_real, lines);
//
//	//test int with  i flag
//	printf("test int with i flag\n\n");
//	count_ft = ft_printf("%i\n", a);
//	count_real = printf("%i\n", a);
//	printf("%d\n%d\n%s", count_ft, count_real, lines);
//
//
//	//test hex lower 
//	printf("test hex lower\n\n");
//	unsigned int g = 4294967295;
//	unsigned int h = -2342340;
//	unsigned int i = 10023232;
//	count_ft = ft_printf("%x\n%x\n%x\n\n", g, h, i);
//	count_real = printf("%x\n%x\n%x\n\n", g, h, i);
//	printf("%d\n%d\n%s", count_ft, count_real, lines);
//
//	//test hex upper 
//	printf("test hex upper\n\n");
//	count_ft = ft_printf("%X\n%X\n%X\n\n", g, h, i);
//	count_real = printf("%X\n%X\n%X\n\n", g, h, i);
//	printf("%d\n%d\n%s", count_ft, count_real, lines);
//
//	//test unsigned int
//	printf("test unsigned int\n\n");
//	count_ft = ft_printf("%u\n%u\n%u\n\n", g, h, i);
//	count_real = printf("%u\n%u\n%u\n\n", g, h, i);
//	printf("%d\n%d\n%s", count_ft, count_real, lines);
//	
//	//test ptr 
//	printf("test ptr\n\n");
//	int sep = 789;
//	float db = 10.34f;
//	int *j = NULL;
//	char *k = "allobonjour";
//	float *l = NULL;
//	char *zero;
//	zero = 0;
//	j = &sep;
//	l = &db;
//	count_ft = ft_printf("%p\n%p\n%p\n%p\n\n", j, k, l, zero);
//	count_real = printf("%p\n%p\n%p\n%p\n\n", j, k, l, zero);
//	printf("%d\n%d\n%s", count_ft, count_real, lines);
//
//	//test ptr //
//	printf("test ptr\n\n");
//	long un_int;
//	long *ptr;
//	long int nul = -2147483648;
//	long int *zer;
//	zer = (long int *)nul;
//
//	un_int = 2147483647;
//	ptr = (long int *)un_int ;
//	count_ft = ft_printf("%p\n%p\n", ptr, zer);
//	count_real = printf("%p\n%p\n", ptr, zer);
//	printf("%d\n", count_ft);
//	printf("%d\n", count_real);
//	return (0);
//}
