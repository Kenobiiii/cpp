/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:19:26 by paromero          #+#    #+#             */
/*   Updated: 2025/10/18 13:45:37 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called - Type: " << type_ << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        type_ = other.type_;
        Animal::operator=(other);
	    *brain = *other.brain;
        std::cout << "Cat assignment operator called - Type: " << type_ << std::endl;
    }
    return *this;
}

void    Cat::MakeSound() const {
    std::cout << "Meow" << std::endl;
}