/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:47:06 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/27 18:17:21 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "libft/libft.h"

void	ft_end_of_symbol(char *c, int *i)
{
	if (c == '\0')
		ft_putstr_fd("\n", 0);
	ft_putchar_fd(*c, 0);
	*c = 0;
	*i = 0;
}

void	ft_server_handler(int signo, siginfo_t *siginfo, void *unused)
{
	static char		c;
	static int		i;
	static pid_t	client_pid;

	(void)unused;
	if (client_pid != 0 && client_pid != siginfo->si_pid)
	{
		c = 0;
		i = 0;
		ft_putstr_fd("\n", 0);
	}
	client_pid = siginfo->si_pid;
	if (signo == SIGUSR1)
		c = c | (1 << i);
	usleep(100);
	if (kill(client_pid, SIGUSR1) == -1)
	{
		i = 0;
		c = 0;
		return ;
	}
	i++;
	if (i == 8)
		ft_end_of_symbol(&c, &i);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	(void)argv;
	if (argc > 1)
	{
		ft_putstr_fd("\n⚠️ Error: server takes no arguments! ⚠️\n", 0);
		return (0);
	}
	ft_putstr_fd("PID:", 0);
	ft_putnbr_fd(getpid(), 0);
	ft_putstr_fd("\n", 0);
	act.sa_sigaction = &ft_server_handler;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGUSR1);
	sigaddset(&act.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
