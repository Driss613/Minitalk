/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <drabarza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:13:52 by drabarza          #+#    #+#             */
/*   Updated: 2024/05/06 18:43:46 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int			g_test = 0;

static int	arguments_is_valid(const char *nptr, long nbr, int sign, int i)
{
	if (nbr * sign < -2147483648 || nbr * sign > 2147483647)
		return (1);
	if (nptr[i] != '\0')
		return (1);
	return (0);
}

static int	ft_atoi(const char *nptr)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	calculint(nptr, i);
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nbr = 10 * nbr + (nptr[i] - 48);
		i++;
	}
	if (arguments_is_valid(nptr, nbr, sign, i))
		return (0);
	return (nbr * sign);
}

static void	reception(int signal)
{
	(void)signal;
	g_test = 1;
}

static void	signal_manager(int pid, char octet)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_test = 0;
		if (octet & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		while (g_test != 1)
			pause();
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3 || argv[2][0] == '\0')
	{
		write(1, "Error arguments\n", 16);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || kill(pid, 0))
	{
		write(1, "Error PID is not valid\n", 23);
		return (1);
	}
	signal(SIGUSR1, reception);
	while (argv[2][i])
	{
		signal_manager(pid, argv[2][i]);
		i++;
	}
	signal_manager(pid, argv[2][i]);
	return (0);
}
