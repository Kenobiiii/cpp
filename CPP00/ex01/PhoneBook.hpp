/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:43:30 by paromero          #+#    #+#             */
/*   Updated: 2025/06/17 15:09:30 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <sstream>

class PhoneBook {
    private:
        Contact contacts_[8];
        int currentIndex_;
        int totalContacts_;

        std::string getInput(const std::string& prompt) const;
        void displayContactsTable() const;
        void displayContactRow(int index, const Contact& contact) const;

    public:
        PhoneBook();
        ~PhoneBook();

    void addContact();
    void searchContact() const;
};

#endif