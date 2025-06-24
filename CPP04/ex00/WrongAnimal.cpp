/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:31:51 by paromero          #+#    #+#             */
/*   Updated: 2025/06/24 11:31:52 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string& type) : type_(type) {
    std::cout << "WrongAnimal constructor called - Type: " << type_ << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called - Type: " << type_ << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type_(other.type_) {
    std::cout << "WrongAnimal copy constructor called - Type: " << type_ << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other) {
        type_ = other.type_;
        std::cout << "WrongAnimal assignment operator called - Type: " << type_ << std::endl;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "Some generic wrong animal sound!" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type_;
}
