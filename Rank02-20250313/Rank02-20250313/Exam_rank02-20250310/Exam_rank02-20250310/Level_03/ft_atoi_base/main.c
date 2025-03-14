#include <stdio.h>
#include <stdlib.h>

int	ft_atoi_base(const char *str, int base);


/* int		main(void)
{
	printf("011 base 2, me: %d, should be: 3\n", ft_atoi_base("011", atoi("2")));
	printf("16 base 8, me:%d, should be: 14\n", ft_atoi_base("16", atoi("8")));
	printf("123 base 10, me:%d, should be: 123\n", ft_atoi_base("123", atoi("10")));
	printf("FF base 16, me:%d, should be: 255\n", ft_atoi_base("FF", atoi("16")));
} */

int		main(int ac, char	**av)
{
	if (ac == 3)
		printf("re: %d\n", ft_atoi_base(av[1], atoi(av[2])));
	return (0);
}

