/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:47:33 by paromero          #+#    #+#             */
/*   Updated: 2025/10/18 11:45:41 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(const std::string& type) {
    this->type_ = type;
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
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

void    Animal::MakeSound() const {
    std::cout << "Some generic animal sound" << std::endl;
}