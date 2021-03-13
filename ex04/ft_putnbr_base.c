/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:11:54 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/13 13:23:05 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_len(char *ptr)
{
	int i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

int		ft_exception(char *ptr)
{
	int i;
	int j;

	i = 0;
	if (ptr[0] == 0 || ptr[1] == 0)
		return (1);
	while (ptr[i])
	{
		if (ptr[i] == '-' || ptr[i] == '+' || ptr[i] <= 31 || ptr[i] == 127)
			return (1);
		j = i + 1;
		while (ptr[j])
		{
			if (ptr[i] == ptr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long	int lnbr;
	int		len1;
	char	str[32];

	len1 = ft_len(base);
	if (ft_exception(base))
		return ;
	i = 0;
	lnbr = nbr;
	if (lnbr < 0)
	{
		ft_putchar('-');
		lnbr = -lnbr;
	}
	while (lnbr != 0)
	{
		str[i++] = lnbr % len1;
		lnbr = lnbr / len1;
	}
	while (--i >= 0)
		ft_putchar(base[(int)str[i]]);
}
