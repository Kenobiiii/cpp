/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:43:28 by paromero          #+#    #+#             */
/*   Updated: 2025/06/19 17:26:45 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//- Constructor: initializes the counters
PhoneBook::PhoneBook() : currentIndex_(0), totalContacts_(0) {
}

//- Destructor
PhoneBook::~PhoneBook() {
}

std::string PhoneBook::DeleteSpaces(const std::string& str) const {
    size_t start = 0;
    size_t end = str.length();
    
    while (start < end && str[start] == ' ') {
        start++;
    }
    
    //- Find last non-space/tab character
    while (end > start && str[end - 1] == ' ') {
        end--;
    }
    
    return str.substr(start, end - start);
}

bool PhoneBook::is_alphanumeric(const std::string& str) const {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isalnum(str[i]) && str[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool PhoneBook::valid_phonenumber(const std::string& str) const {
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]) && str[i] != ' ') {
            return false;
        }
    }
    if (str.length() < 9 || str.length() > 15)
        return false;
    return true;
}

//- Request input from user and validate it's not empty
std::string PhoneBook::getInput(const std::string& prompt, int i) const {
    std::string input;
    std::string FixedInput;
    
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (std::cin.eof()) {
            std::cout << std::endl;
            exit(0);
        }
        
        FixedInput = DeleteSpaces(input);
        
        if (i && !valid_phonenumber(FixedInput)) {
            std::cout << "Must be a valid phone number" << std::endl;
        }

        else if (FixedInput.empty()) {
            std::cout << "Field cannot be empty. Please try again." << std::endl;
        }
        else if (!is_alphanumeric(FixedInput)) {
            std::cout << "Print alphanumeric values" << std::endl;
        }


    } while (FixedInput.empty() || !is_alphanumeric(FixedInput) || (i && !valid_phonenumber(FixedInput)));
    
    return FixedInput;
}

//- Display one row of the contacts table
void PhoneBook::displayContactRow(int index, const Contact& contact) const {
    std::cout << "|" << std::setw(10) << index; //- setw makes that the value is 10 (in this case) characters wide, if the value is shorter than 10, it fills with spaces
    std::cout << "|" << std::setw(10) << contact.truncateField(contact.getName());
    std::cout << "|" << std::setw(10) << contact.truncateField(contact.getSurname());
    std::cout << "|" << std::setw(10) << contact.truncateField(contact.getNickname());
    std::cout << "|" << std::endl;
}

//- Display the complete contacts table
void PhoneBook::displayContactsTable() const {
    std::cout << "|" << std::setw(10) << "Index";
    std::cout << "|" << std::setw(10) << "First Name";
    std::cout << "|" << std::setw(10) << "Last Name";
    std::cout << "|" << std::setw(10) << "Nickname";
    std::cout << "|" << std::endl;
    
    for (int i = 0; i < totalContacts_; i++) {
        displayContactRow(i + 1, contacts_[i]);
    }
}

//- ADD command: add a new contact
void PhoneBook::addContact() {
    Contact newContact;
    
    std::string name = getInput("Enter first name: ", 0);
    std::string surname = getInput("Enter last name: ", 0);
    std::string nickname = getInput("Enter nickname: ", 0);
    std::string phoneNumber = getInput("Enter phone number: ", 1);
    std::string darkestSecret = getInput("Enter darkest secret: ", 0);
    
    newContact.setName(name);
    newContact.setSurname(surname);
    newContact.setNickname(nickname);
    newContact.setPhoneNumber(phoneNumber);
    newContact.setDarkestSecret(darkestSecret);
    
    contacts_[currentIndex_] = newContact;
    currentIndex_ = (currentIndex_ + 1) % 8;
    
    if (totalContacts_ < 8) {
        totalContacts_++;
    }
    
    std::cout << "Contact added successfully!" << std::endl;
}

//- SEARCH command: search and display contacts
void PhoneBook::searchContact() const {
    if (totalContacts_ == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    displayContactsTable();
    
    std::string input;
    std::cout << "Enter contact index: ";
    std::getline(std::cin, input);
    
    if (std::cin.eof()) {
        std::cout << std::endl;
        exit(0);
    }
    
    std::stringstream ss(input); //- stringstream verify if the input can be transformed to int
    int index;
    
    if (ss >> index && ss.eof() && index > 0 && index <= totalContacts_) {
        contacts_[index - 1].displayContact();
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}