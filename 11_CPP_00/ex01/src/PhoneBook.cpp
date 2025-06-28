#include <iostream>
#include <iomanip>
#include <sstream>
#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(): count(0) {}

void    PhoneBook::addContact()
{
	std::string first, last, nick, phone, secret;

	std::cout << "First name: ";
	std::getline(std::cin, first);
	std::cout << "Last name: ";
	std::getline(std::cin, last);
	std::cout << "Nick name: ";
	std::getline(std::cin, nick);
	std::cout << "Phone number: ";
	std::getline(std::cin, phone);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, secret);

	if (first.empty() || last.empty() || nick.empty() || phone.empty() || secret.empty())
	{
		std::cout << "All fields must be filled!" << std::endl;
		return;
	}
	contacts[count % 8].setContact(first, last, nick, phone, secret);
	count++;
	std::cout << "Add contact successfully!" << std::endl;
}

static std::string formatting(std::string	s)
{
	if (s.length() > 10)
		return (s.substr(0, 9) + ".");
	else
	{
		std::stringstream	cp;
		cp << std::setw(10) << s;
		return (cp.str());
	}
}

void PhoneBook::displayContact() const
{
	int	max;

	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "FirstName" << "|"
			<< std::setw(10) << "LastName" << "|"
			<< std::setw(10) << "NickName" << "|" << std::endl;
	if (count > 8)
		max = 8;
	else
		max = count;
	for (int i = 0; i < max; i++)
	{
		std::cout << std::setw(10) << i << "|"
				<< formatting(contacts[i].getFirstName()) << "|"
				<< formatting(contacts[i].getLastName()) << "|"
				<< formatting(contacts[i].getNickName()) << "|" << std::endl;				
	}
}

void PhoneBook::displayContactLines(int	i) const
{
	int	max;
	max = count;
	if (max > 8)
		max = 8;
	if (i < 0 || i >= max)
	{
		std::cout << "Invalid index input" << std::endl;
		return;
	}
	std::cout << "First name: " << contacts[i].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[i].getLastName() << std::endl;
	std::cout << "Nick name: " << contacts[i].getNickName() << std::endl;
	std::cout << "Phone number: " << contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[i].getDarkestSecret() << std::endl;
}
