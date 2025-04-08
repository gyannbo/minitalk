/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:29:09 by gbonis            #+#    #+#             */
/*   Updated: 2024/07/11 14:04:36 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	check_pid(siginfo_t *info, unsigned char *c, int *bt_ind, pid_t *pid)
{
	if (!(*pid))
		*pid = info->si_pid;
	if (*pid != info->si_pid)
	{
		*pid = info->si_pid;
		*c = 0;
		*bt_ind = 0;
	}
}

void	handle_signal(int signal, siginfo_t *info, void *rien)
{
	static unsigned char	current_char;
	static int				bit_index;
	static pid_t			pid;

	check_pid(info, &current_char, &bit_index, &pid);
	current_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == END_OF_COM)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &current_char, 1);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
	kill(info->si_pid, SIGUSR1);
	rien++;
}

int	main(void)
{
	struct sigaction	act;
	struct sigaction	actbis;

	act.sa_sigaction = handle_signal;
	actbis.sa_sigaction = handle_signal;
	act.sa_flags = (SA_SIGINFO);
	actbis.sa_flags = (SA_SIGINFO);
	sigemptyset(&act.sa_mask);
	sigemptyset(&actbis.sa_mask);
	ft_printf("%d\n", getpid());
	w_sigaction(SIGUSR1, &act);
	w_sigaction(SIGUSR2, &actbis);
	while (1)
		;
	return (0);
}
