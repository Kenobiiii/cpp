/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:50:26 by paromero          #+#    #+#             */
/*   Updated: 2025/10/18 13:44:17 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called - Type: " << type_ << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        type_ = other.type_;
        Animal::operator=(other);
	    *brain = *other.brain;
        std::cout << "Dog assignment operator called - Type: " << type_ << std::endl;
    }
    return *this;
}

void    Dog::MakeSound() const {
    std::cout << "Woof Woof" << std::endl;
}