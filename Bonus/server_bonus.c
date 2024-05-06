/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <drabarza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:13:49 by drabarza          #+#    #+#             */
/*   Updated: 2024/05/06 13:09:25 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	write_signal(int signal, siginfo_t *signals, void *content)
{
	static int	i = 0;
	static char	letter = 0;
	static char	*str = NULL;

	(void)content;
	if (signal == SIGUSR1)
		letter |= (1 << i);
	i++;
	if (i == 8)
	{
		str = ft_strjoin(str, &letter);
		i = -1;
		if (letter == '\0')
		{
			while (str[++i])
				write(1, &str[i], 1);
			free(str);
			str = NULL;
		}
		i = 0;
		letter = 0;
	}
	kill(signals->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	signals;

	signals.sa_sigaction = write_signal;
	signals.sa_flags = SA_SIGINFO;
	sigemptyset(&signals.sa_mask);
	ft_putnbr_base10(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &signals, NULL);
	sigaction(SIGUSR2, &signals, NULL);
	while (1)
		pause();
	return (0);
}
