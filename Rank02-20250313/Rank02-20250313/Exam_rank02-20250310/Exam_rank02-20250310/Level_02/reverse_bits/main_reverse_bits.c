#include <stdio.h>

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}
unsigned char	reverse_bits(unsigned char	octet);

int	main(void)
{
	unsigned char oc;

	oc = 2;
    printf("octet 2 bits be: 00000010\n");
	printf("print_bits is: \n");
	print_bits(oc);
	printf("\n");
	printf("reverse_bits is: \n");
	oc = reverse_bits(oc);
	print_bits(oc);
	printf("\n");

    oc = 13;
    printf("octet 13 bits be: 00001101\n");
    printf("print_bits is: \n");
	print_bits(oc);
	printf("\n");
	printf("reverse_bits is: \n");
	oc = reverse_bits(oc);
	print_bits(oc);
	printf("\n");

    oc = 26;
    printf("octet 26 bits be: 00011010\n");
    printf("print_bits is: \n");
	print_bits(oc);
	printf("\n");
	printf("reverse_bits is: \n");
	oc = reverse_bits(oc);
	print_bits(oc);
	printf("\n");

	return (0);
}