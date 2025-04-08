/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:29:01 by gbonis            #+#    #+#             */
/*   Updated: 2024/07/11 14:04:37 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h" 

void	ft_nothing(int signal)
{
	signal++;
}

void	print_end_com(int signal)
{
	ft_printf("message fully received \n");
	signal++;
}

void	parse_pid(char *pid_string)
{
	pid_t	pid;
	int		i;
	int		overflow;

	overflow = 0;
	i = -1;
	while (pid_string[++i])
	{
		if (!ft_strchr("0123456789", pid_string[i]))
		{
			ft_printf("incorrect pid number\n");
			exit(-1);
		}
	}
	pid = ft_atoi(pid_string);
	if (pid <= 0 || pid > PID_MAX)
	{
		ft_printf("incorrect pid number\n");
		exit(-1);
	}
}

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100000);
	}
}

int	main(int argc, char *argv[])
{
	pid_t					server_pid;
	const char				*message;
	int						i;
	struct sigaction		act;
	struct sigaction		actbis;

	if (argc != 3)
		exit(0);
	parse_pid(argv[1]);
	act.sa_handler = ft_nothing;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	w_sigaction(SIGUSR1, &act);
	actbis.sa_handler = print_end_com;
	actbis.sa_flags = 0;
	sigemptyset(&actbis.sa_mask);
	w_sigaction(SIGUSR2, &actbis);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
		send_signal(server_pid, message[i++]);
	send_signal(server_pid, END_OF_COM);
	sleep(1);
	return (0);
}
