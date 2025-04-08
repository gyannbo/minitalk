/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:57:07 by gbonis            #+#    #+#             */
/*   Updated: 2024/01/31 19:23:12 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h" 

int			ft_print_arg(char type, va_list args);
int			ft_parse(char *str, va_list args);
int			ft_printf(const char *format, ...);
int			ft_istype(int c);
int			ft_print_str(const char *str);
int			ft_print_char(char c);
int			ft_print_int(long unsigned int x);
int			ft_print_hex(unsigned int num, int is_upper);
int			ft_print_unsigned(unsigned int num);
int			ft_print_ptr(unsigned long int num);
size_t		ft_xtoa_len(unsigned long num);
char		*ft_hex_to_str(unsigned long int num, char *str, size_t len);

#endif
