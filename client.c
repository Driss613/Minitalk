/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <drabarza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:13:52 by drabarza          #+#    #+#             */
/*   Updated: 2024/04/28 21:20:11 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	gestionnaire_signal(int pid, char octet)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (octet >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(400);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc < 2)
		printf("Error PID\n");
	else if (argc > 3 || argc == 2)
		printf("Error args\n");
	else
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			printf("Error PID is not valid\n");
		while (argv[2][i])
		{
			gestionnaire_signal(pid, argv[2][i]);
			i++;
		}
	}
	return (0);
}
