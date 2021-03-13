#include <stdio.h>
#include <unistd.h>

int	ft_len(char *arr)
{
	int i;

	i = 0;
	while(arr[i] != 0)
	{
		i++;
	}
	return i;
}


int	ft_sub(char ch,char *base)
{
	int i;

	i = 0;
	while(base[i] != 0)
	{
		if(base[i] == ch)
			return i;
		i++;	
	}
	return -1;
}

int	ft_base_exception(char *base)
{
	int i;

	if (base[0] == 0 || base[1] == 1)
		return 1;
	while(*base != 0)
	{
		if (*base =='+' || *base =='-' || *base == ' ' || (*base >= 9 && *base <= 13)
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

int	ft_str_exception(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)
			i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}

}
int	ft_atoi_base(char *str, char *base)
{
	int sum;
	int base_len;
	int n;
	int result;

	base_len = ft_len(base);
	sum  = 0;
	while (*str)
	{
		if(ft_sub(*str,base) == -1)
			return 0;
		sum *= 10;
		sum += ft_sub(*str,base);
		str++;
	}
	n = 1;
	result = 0;
	while(sum != 0)
	{
		result = result + ( sum % 10  * n);
		n *= base_len;
		sum /= 10;
	}
	return result;
}

int main(void)
{
	char arr[10] = { 0, };
	printf("%s", arr);
//	printf("%d\n", ft_atoi_base(" ---+-+pyevni??", "poneyvif"));  // str을 먼저 숫자로 바꿀 수 없다. 무조건 기수에 대입하는게 먼저다.
	printf("%d\n", ft_atoi_base("opyevni", "poneyvif"));
	return 0;
}
