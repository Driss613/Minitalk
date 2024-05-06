/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabarza <drabarza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:06:12 by drabarza          #+#    #+#             */
/*   Updated: 2024/05/06 13:08:59 by drabarza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	calculint(const char *nptr, int i)
{
	int	countnumber;

	countnumber = 0;
	while (nptr[i] == '0')
		i++;
	while (nptr[i])
	{
		i++;
		countnumber++;
	}
	if (countnumber > 10)
		exit(1);
}

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strdup(const char *s)
{
	char	*tab;
	int		i;

	i = 0;
	if (s[0] == '\0')
		return (NULL);
	tab = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tab)
		exit (1);
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		lens1;
	int		i;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	lens1 = ft_strlen(s1);
	i = -1;
	tab = malloc(sizeof(char) * (lens1 + 1) + 1);
	if (!tab)
	{
		free(s1);
		exit(1);
	}
	while (lens1 > ++i)
		tab[i] = s1[i];
	tab[i] = s2[0];
	tab[++i] = '\0';
	free(s1);
	return (tab);
}

int	ft_putnbr_base10(int n)
{
	int	sign;

	sign = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * (-1);
		sign++;
	}
	if (n > 9)
		ft_putnbr_base10(n / 10);
	write(1, &(char){n % 10 + '0'}, 1);
	return (0);
}
