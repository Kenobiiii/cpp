/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:02:17 by paromero          #+#    #+#             */
/*   Updated: 2025/06/06 12:43:25 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(const std::string& type) : type_(type) {
    std::cout << "Animal constructor called - Type: " << type_ << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called - Type: " << type_ << std::endl;
}

Animal::Animal(const Animal& other) : type_(other.type_) {
    std::cout << "Animal copy constructor called - Type: " << type_ << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type_ = other.type_;
        std::cout << "Animal assignment operator called - Type: " << type_ << std::endl;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Some generic animal sound!" << std::endl;
}

std::string Animal::getType() const {
    return type_;
}