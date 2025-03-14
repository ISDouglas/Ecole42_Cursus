#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char	**av)
{
	if (ac == 2)
	{
		printf("number %s is :\n", av[1]);
		printf("atoi : %d\n", atoi(av[1]));
		printf("ft_atoi : %d\n", atoi(av[1]));
	}
	else
		printf("enter number : \n");
	return (0);
}
//cc -Werror -Wall -Wextra