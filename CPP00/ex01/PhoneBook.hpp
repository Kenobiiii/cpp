/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:43:30 by paromero          #+#    #+#             */
/*   Updated: 2025/06/24 11:34:07 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cctype>

class PhoneBook {
    private:
        Contact contacts_[8];
        int currentIndex_;
        int totalContacts_;

        std::string getInput(const std::string& prompt, int i) const;
        void displayContactsTable() const;
        void displayContactRow(int index, const Contact& contact) const;
        std::string DeleteSpaces(const std::string& str) const;
        bool is_alphanumeric(const std::string& str) const;
        bool valid_phonenumber(const std::string& str) const;

    public:
        PhoneBook();
        ~PhoneBook();

    void addContact();
    void searchContact() const;
};