#include <stdio.h>
#include <stdlib.h>

int	*ft_rrange(int start, int end);

void	print_array(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%d : %d\n", i, tab[i]);
		i++;
	}
}

int	main(void)
{
	int	*nbs;

	nbs = ft_rrange(1, 3);
	printf("(1, 3) : \n");
	print_array(nbs, 3);
	free(nbs);

	nbs = ft_rrange(-1, 2);
	printf("(-1, 2) : \n");
	print_array(nbs, 4);
	free(nbs);

	nbs = ft_rrange(0, 0);
	printf("(0, 0) : \n");
	print_array(nbs, 1);
	free(nbs);

	nbs = ft_rrange(0, -3);
	printf("(0, -3) : \n");
	print_array(nbs, 4);
	free(nbs);

	return (0);
}
