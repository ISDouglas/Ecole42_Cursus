#include <stdio.h>

char	*ft_strrev(char	*str);

int main(void)
{
	char s[] = "hello_world";
	
	printf("strrev hello_world: %s\n", ft_strrev(s));
	
	char s2[] = "123456789";
	
	printf("strrev 123456789: %s\n", ft_strrev(s2));
	
	return 0;
}
