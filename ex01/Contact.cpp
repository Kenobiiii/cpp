/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:15:16 by paromero          #+#    #+#             */
/*   Updated: 2025/05/31 19:35:05 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

//- Constructor
Contact::Contact() {
}

//- Destructor
Contact::~Contact() {
}

//- SETTERS: Assign the private values
void Contact::setName(const std::string& name) {
    name_ = name;
}

void Contact::setSurname(const std::string& surname) {
    surname_ = surname;
}

void Contact::setNickname(const std::string& nickname) {
    nickname_ = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
    phoneNumber_ = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
    darkestSecret_ = darkestSecret;
}

//- GETTERS: get the private values
std::string Contact::getName() const {
    return name_;
}

std::string Contact::getSurname() const {
    return surname_;
}

std::string Contact::getNickname() const {
    return nickname_;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber_;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret_;
}

//? UTILITY FUNCTIONS

//- Check if is empty
/*
* .empty checks if the string in fact is empty, if is empty, return (1), if not, 0,
* function of #include <string.h>
*/
bool Contact::isEmpty() const {
    return name_.empty();
}

//- Show all the information of the contact
void Contact::displayContact() const {
    std::cout << "First Name: " << name_ << std::endl;
    std::cout << "Last Name: " << surname_ << std::endl;
    std::cout << "Nickname: " << nickname_ << std::endl;
    std::cout << "Phone Number: " << phoneNumber_ << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret_ << std::endl;
}

//- if contact surpass 10 characters, add a point
std::string Contact::truncateField(const std::string& field) const {
    if (field.length() > 10) {
        return field.substr(0, 9) + ".";
    }
    return field;
}
