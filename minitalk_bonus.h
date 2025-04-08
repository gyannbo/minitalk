/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:30:57 by gbonis            #+#    #+#             */
/*   Updated: 2024/07/10 12:23:30 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

# define PID_MAX 4194304
# define END_OF_COM '\0'

void	w_sigaction(int sig, struct sigaction *act, struct sigaction *oldcact);

#endif
