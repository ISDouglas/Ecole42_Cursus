#include <stdio.h>

void	print_bits(unsigned char octet);

int	main(void)
{
	unsigned char oc;

	oc = 2;
    printf("octet 2 bits be: 00000010\n");
    printf("print_bits is\n");
	print_bits(oc);
	printf("\n");

    oc = 13;
    printf("octet 13 bits be: 00001101\n");
    printf("print_bits is\n");
	print_bits(oc);
	printf("\n");

    oc = 26;
    printf("octet 26 bits be: 00011010\n");
    printf("print_bits is\n");
	print_bits(oc);
	printf("\n");

	return (0);
}
