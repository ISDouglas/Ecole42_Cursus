#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char	*s, const char	*reject);

int main(void)
{
	const char *s = "hello world";
	const char *reject = "e";
	
	printf("strcspn: %zu\n", strcspn(s, reject));
	printf("ft_strcspn: %zu\n", ft_strcspn(s, reject));
	
	const char *s2 = "123456789";
	const char *reject2 = "8";
	
	printf("strcspn: %zu\n", strcspn(s2, reject2));
	printf("ft_strcspn: %zu\n", ft_strcspn(s2, reject2));
	
	return 0;
}
