#include "../includes/Contact.hpp"

Contact::Contact(){}

void    Contact::setContact(std::string first, std::string last, std::string nick,
    std::string phone, std::string secret)
{
    _firstName = first;
    _lastName = last;
    _nickName = nick;
    _phoneNumber = phone;
    _darkestSecret = secret;
}

std::string Contact::getFirstName() const 
{
	return _firstName;
}

std::string Contact::getLastName() const 
{
	return _lastName;
}

std::string Contact::getNickName() const 
{
	return _nickName;
}

std::string Contact::getPhoneNumber() const 
{
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() const 
{
	return _darkestSecret;
}
