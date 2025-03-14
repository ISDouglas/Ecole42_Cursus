#include <string.h>
#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept);

int main(void)
{
	const char *s = "hello world";
	const char *accept = "hello world";
	
	printf("strspn: %zu\n", strspn(s, accept));
	printf("ft_strspn: %zu\n", ft_strspn(s, accept));
	
	const char *s2 = "123456789";
	const char *accept2 = "2";
	
	printf("strspn: %zu\n", strspn(s2, accept2));
	printf("ft_strspn: %zu\n", ft_strspn(s2, accept2));
	
	return 0;
}
