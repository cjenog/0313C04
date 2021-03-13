#include <stdio.h>
#include <unistd.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int	ft_len(char *base)
{
	int i;
	i = 0;
	while(base[i])
		i++;
	return i;
}

int	ft_exception(char *base)
{
	int i;

	if(base[0] == 0 || base[1] == 0)
		return 1;

	while(*base != 0)
	{

		if (*base == '-' || *base == '+')
			return 1;
		i = 1;
		while (base[i] != 0)
		{
			if (*base == base[i])
				return 1;
			i++;
		}
		base++;
	}

	return 0;
}

void	ft_rec(unsigned int u_nbr,int base_len, char *base)
{
	if(u_nbr >= base_len)
	{
		ft_rec(u_nbr / base_len, base_len, base);
		ft_putchar(base[u_nbr % base_len]);
	}
	else
		ft_putchar(base[u_nbr % base_len]);
}


void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int u_nbr;
	int base_len = ft_len(base);
	
	if(ft_exception(base) == 1)
		return ;

	u_nbr = nbr;
	if(nbr < 0)
	{
		u_nbr = -nbr;
		ft_putchar('-');
	}

	ft_rec(u_nbr,base_len,base);
	
}


int	main()
{
	int nbr =-2147483648;
	char base[20] = "01";
	ft_putnbr_base(nbr,base);
	return 0;
}
