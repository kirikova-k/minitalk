/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:20:35 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/27 18:22:08 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "libft/libft.h"

t_inf	g_info;

void	ft_init_void(int *signo, siginfo_t *siginfo, void *unused)
{
	(void)unused,
	(void)siginfo;
	(void)*signo;
}

void	ft_print_error(int flag)
{
	if (flag == 0)
		ft_putstr_fd("\n✉️✔️  Messege recived! ✉️✔️\n", 0);
	if (flag == 1)
		ft_putstr_fd("\n⚠️  Server is not available! ⚠️\n", 0);
	if (flag == 2)
		ft_putstr_fd("\n⚠️  Error server! ⚠️\n", 0);
	exit (0);
}

int	ft_check_pid(char *str_pid)
{
	int	i;
	int	pid;

	i = 0;
	pid = 0;
	while (str_pid[i])
	{
		if (!ft_isdigit(str_pid[i]))
			ft_print_error(2);
		i++;
	}
	pid = ft_atoi(str_pid);
	if (pid <= 0)
		ft_print_error(2);
	return (pid);
}

void	ft_client_handler(int signo, siginfo_t *siginfo, void *unused)
{
	static int	counter;
	static int	i;

	ft_init_void(unused, siginfo, &signo);
	g_info.t = 0;
	usleep(100);
	if (g_info.msg[i] == '\0' && counter == 8)
		ft_print_error(0);
	if (counter == 8)
	{
		counter = 0;
		i++;
	}
	if ((g_info.msg[i] >> counter) & 1)
	{
		if (kill(g_info.pid, SIGUSR1) == -1)
			ft_print_error(1);
	}
	else
	{
		if (kill(g_info.pid, SIGUSR2) == -1)
			ft_print_error(1);
	}
	counter++;
	usleep(100);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	if (argc != 3)
		return (write(0, "You must enter 3 arguments: \
	[./client] [PID] [message]\n", 57));
	g_info.msg = argv[2];
	g_info.pid = ft_check_pid(argv[1]);
	g_info.t = 0;
	act.sa_sigaction = &ft_client_handler;
	sigaction(SIGUSR1, &act, 0);
	ft_client_handler(0, NULL, NULL);
	while (1)
	{
		if (g_info.t > 3)
			ft_print_error(1);
		sleep(1);
		g_info.t++;
	}
	return (0);
}
