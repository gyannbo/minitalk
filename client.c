/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:29:01 by gbonis            #+#    #+#             */
/*   Updated: 2024/07/11 13:52:09 by gbonis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h" 

void	ft_nothing(int signal)
{
	signal++;
}

void	parse_pid(char *pid_string)
{
	pid_t	pid;
	int		i;
	//int		overflow;

//	overflow = 0;        // dont know what this is used for
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

	if (argc != 3)
	{
		ft_printf("usage : ./client <PID> <your_string>\n");
		exit(0);
	}
	parse_pid(argv[1]);
	act.sa_handler = ft_nothing;
	act.sa_flags = 0;
	sigemptyset(&act.sa_mask);
	w_sigaction(SIGUSR1, &act);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
		send_signal(server_pid, message[i++]);
	send_signal(server_pid, END_OF_COM);
	return (0);
}
