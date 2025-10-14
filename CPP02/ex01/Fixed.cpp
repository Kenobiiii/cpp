/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 08:55:39 by paromero          #+#    #+#             */
/*   Updated: 2025/10/14 09:48:46 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    value_ = 0;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->value_ = other.getRawBits();    
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->value_ = value << this->FractionalBits_ ;    
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->value_ = (int)roundf(value * (1 << this->FractionalBits_)) ;    
}  

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->value_ = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value_;
}

void Fixed::setRawBits(int const raw) {
    this->value_ = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->value_ / (1 << this->FractionalBits_);
}

int Fixed::toInt(void) const {
    return this->value_ >> this->FractionalBits_;
}

std::ostream& operator<<(std::ostream& out, const Fixed& other) {
    out << other.toFloat();
    return out;
}