#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int     count;
	public:
		// Constructor
		PhoneBook();
		// Member functions
		void	addContact();
		void	displayContact() const;
		void	displayContactLines(int	i) const;
};

#endif
