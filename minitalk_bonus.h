/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogarthar <ogarthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:43:23 by ogarthar          #+#    #+#             */
/*   Updated: 2021/09/27 18:17:04 by ogarthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>

typedef struct s_inf
{
	char	*msg;
	int		pid;
	int		t;
}t_inf;

///server.c///
int		main(int argc, char **argv);
void	ft_server_handler(int signo, siginfo_t *siginfo, void *unused);
void	ft_end_of_symbol(char *c, int *i);

///client.c///
int		main(int argc, char **argv);
void	ft_client_handler(int signo, siginfo_t *siginfo, void *unused);
int		ft_check_pid(char *pid);
void	ft_print_error(int flag);
void	ft_init_void(int *signo, siginfo_t *siginfo, void *unused);

#endif
