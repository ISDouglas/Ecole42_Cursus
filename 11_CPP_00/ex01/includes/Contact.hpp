#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
	public:
		// Constructor
		Contact();
		// Member functions
		void	setContact(std::string first, std::string last, std::string nick,
				std::string phone, std::string secret);
		std::string	getFirstName() const;
		std::string	getLastName() const;	
		std::string	getNickName() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
};

#endif
