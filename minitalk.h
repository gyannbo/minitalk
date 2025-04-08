/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:30:57 by gbonis            #+#    #+#             */
/*   Updated: 2024/07/10 12:20:25 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

# define PID_MAX 4194304
# define END_OF_COM '\0'

void	w_sigaction(int sig, struct sigaction *act);

#endif
