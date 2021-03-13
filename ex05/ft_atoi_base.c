/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:15:09 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/13 21:47:31 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char *arr)
{
	int i;

	i = 0;
	while (arr[i] != 0)
	{
		i++;
	}
	return (i);
}

int	ft_sub(char ch, char *base)
{
	int i;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_base_exception(char *base)
{
	int i;

	if (base[0] == 0 || base[1] == 1)
		return (1);
	while (*base != 0)
	{
		if (*base == '+' || *base == '-')
			return (1);
		if (*base == ' ' || (*base >= 9 && *base <= 13))
			return (1);
		i = 1;
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

int	ft_atoi_base(char *str, char *base)
{
	int sum;
	int base_len;
	int sign;

	sign = 1;
	if (ft_base_exception(base) == 1)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	base_len = ft_len(base);
	sum = 0;
	while (ft_sub(*str, base) != -1)
	{
		sum *= base_len;
		sum += ft_sub(*str, base);
		str++;
	}
	return (sum * sign);
}
