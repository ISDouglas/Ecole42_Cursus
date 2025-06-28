#include <iostream>
#include <string>
#include <sstream>
#include "../includes/PhoneBook.hpp"

int main()
{
	PhoneBook	phoneBook;
	std::string input;

	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		if (input == "ADD")
			phoneBook.addContact();
		else if (input == "SEARCH")
		{
			phoneBook.displayContact();
			std::cout << "Enter index: ";
			std::getline(std::cin, input);
			std::istringstream	ss(input);
			int	idx;
			if (!(ss >> idx))
				std::cout << "Invalid input" << std::endl;
			else
				phoneBook.displayContactLines(idx);
		}
		else if (input == "EXIT")
			break;
	}
	return (0);
}
