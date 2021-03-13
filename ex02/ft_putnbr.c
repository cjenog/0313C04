/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:27:30 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/13 13:05:27 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int unb;

	unb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		unb = -nb;
	}
	if (unb >= 10)
	{
		ft_putnbr(unb / 10);
		ft_putchar(unb % 10 + '0');
	}
	else
		ft_putchar(unb + '0');
}
