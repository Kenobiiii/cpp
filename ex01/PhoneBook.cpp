/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:43:28 by paromero          #+#    #+#             */
/*   Updated: 2025/05/31 20:39:30 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

//- Constructor: initializes the counters
PhoneBook::PhoneBook() : currentIndex_(0), totalContacts_(0) {
}

//- Destructor
PhoneBook::~PhoneBook() {
}

//- Request input from user and validate it's not empty
std::string PhoneBook::getInput(const std::string& prompt) const {
    std::string input;
    
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (std::cin.eof()) {
            std::cout << std::endl;
            exit(0);
        }
        
        if (input.empty()) {
            std::cout << "Field cannot be empty. Please try again." << std::endl;
        }
    } while (input.empty());
    
    return input;
}

//- Display one row of the contacts table
void PhoneBook::displayContactRow(int index, const Contact& contact) const {
    std::cout << "|" << std::setw(10) << index;
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
        displayContactRow(i, contacts_[i]);
    }
}

//- ADD command: add a new contact
void PhoneBook::addContact() {
    Contact newContact;
    
    std::string name = getInput("Enter first name: ");
    std::string surname = getInput("Enter last name: ");
    std::string nickname = getInput("Enter nickname: ");
    std::string phoneNumber = getInput("Enter phone number: ");
    std::string darkestSecret = getInput("Enter darkest secret: ");
    
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
    
    std::stringstream ss(input);
    int index;
    
    if (ss >> index && ss.eof() && index >= 0 && index < totalContacts_) {
        contacts_[index].displayContact();
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

//- Main loop
void PhoneBook::run() {
    std::string command;
    
    std::cout << "Welcome to your PhoneBook!" << std::endl;
    
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        
        if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        }
        
        if (command == "ADD") {
            addContact();
        }
        else if (command == "SEARCH") {
            searchContact();
        }
        else if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else {
            std::cout << "Invalid command. Use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
}