#include <string.h>
#include <stdio.h>

char	*ft_strpbrk(const char	*s1, const char	*s2);

int main(void)
{
	const char *s = "hello_world";
	const char *accept = "_h";
	
	printf("strpbrk: %s\n", strpbrk(s, accept));
	printf("ft_strpbrk: %s\n", ft_strpbrk(s, accept));
	
	const char *s2 = "123456789";
	const char *accept2 = "0";
	
	printf("strpbrk: %s\n", strpbrk(s2, accept2));
	printf("ft_strpbrk: %s\n", ft_strpbrk(s2, accept2));
	
	return 0;
}
