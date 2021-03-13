#include <stdio.h>
int	ft_atoi_base(char* str, char* base);

int main(void)
{
	char arr[10] = { 0, };
	printf("%s", arr);
	printf("%d\n", ft_atoi_base(" ---+-+opyevni??", "poneyvif"));  // str을 먼저 숫자로 바꿀 수 없다. 무조건 기수에 대입하는게 먼저다.
//	printf("%d\n", ft_atoi_base("opyevni", "poneyvif"));  // str을 먼저 숫자로 바꿀 수 없다. 무조건 기수에 대입하는게 먼저다.
	return 0;
}
