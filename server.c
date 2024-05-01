/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <drabarza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:13:49 by drabarza          #+#    #+#             */
/*   Updated: 2024/04/28 21:23:02 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	write_signal(int signal)
{
	static int	i = 0;
	static char	letter = 0;

	if (signal == SIGUSR1)
		letter |= 1 << i;
	else
		letter |= 0 << i;
	i++;
	if (i == 8)
	{
		write(1, &letter, 1);
		i = 0;
		letter = 0;
	}
}

int	main(void)
{
	printf("%d\n", getpid());
	signal(SIGUSR1, write_signal);
	signal(SIGUSR2, write_signal);
	while (1)
		continue ;
}
