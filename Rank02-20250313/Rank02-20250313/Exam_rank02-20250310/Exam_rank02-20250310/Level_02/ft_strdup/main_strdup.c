#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strdup(char	*src);

int	main(void)
{
	char	*s1;
	char	*s2;

	s2 = "call12345";
	s1 = ft_strdup(s2);
	if (s1 != NULL)
	{
		printf("src: %s\n", s2);
        printf("dup src: %s\n", s1);
        free(s1);
	}
	return (0);
}
