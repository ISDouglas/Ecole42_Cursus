
#include <stdio.h>

int	max(int* tab, unsigned int len);

int main(void)
{
	int tab[] = {2, 6, 7, 12, 9};
	printf("max in tab is: %d\n", max(tab, 0));

	int tab2[] = {2, 100, 100, 7, 12, 0};
	printf("max in tab2 is: %d\n", max(tab2, 6));
	
	return 0;
}
