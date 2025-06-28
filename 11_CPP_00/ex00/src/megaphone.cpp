#include <iostream>
#include <string>

int	main(int argc, char	*argv[])
{
	std::string	str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	if (argc == 1)
		std::cout << str;
	else
	{
		for (int i = 1; i < argc; i++){
			for (int j = 0; argv[i][j] != '\0'; j++){
				std::cout << (char)std::toupper(argv[i][j]);
			}
		}
	}
	std::cout << std::endl;
	return (0);
}
