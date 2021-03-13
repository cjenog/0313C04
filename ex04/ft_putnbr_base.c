/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:45:01 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/13 21:38:40 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_len(char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

void	ft_change(long nbr, int base_len, char *base)
{
	if (nbr >= base_len)
	{
		ft_change(nbr / base_len, base_len, base);
		ft_putchar(base[nbr % base_len]);
	}
	else
		ft_putchar(base[nbr % base_len]);
}

int		ft_exception(char *base)
{
	int i;

	if (base[1] == 0 || base[0] == 0)
		return (1);
	while (*base != 0)
	{
		i = 1;
		if (*base == '-' || *base == '+')
			return (1);
		while (base[i] != 0)
		{
			if (*base == base[i])
				return (1);
			i++;
		}
		base++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	l_nbr;

	if (ft_exception(base) == 1)
		return ;
	l_nbr = nbr;
	if (l_nbr < 0)
	{
		ft_putchar('-');
		l_nbr = -l_nbr;
	}
	base_len = ft_len(base);
	ft_change(l_nbr, base_len, base);
}
