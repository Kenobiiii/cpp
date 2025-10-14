/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 08:55:39 by paromero          #+#    #+#             */
/*   Updated: 2025/10/14 11:06:34 by paromero         ###   ########.fr       */
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
  
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

//! BOOLS
bool Fixed::operator>(const Fixed& other) const {
    return getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
    return getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
    return getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
    return getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
    return getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
    return getRawBits() != other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    this->value_ = other.getRawBits();
    return *this;
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + other.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->getRawBits() - other.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    long long tmp = (long long)this->value_ * other.value_;
    result.setRawBits(tmp >> this->FractionalBits_);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.value_ == 0)
        return 0;

    Fixed result;
    long long tmp = ((long long)this->value_ << this->FractionalBits_);
    result.setRawBits(tmp / other.value_);
    return result;
}

//! Increment & decrement

Fixed &Fixed::operator++() {
    this->value_ += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed old;
    old.value_ = this->value_;
    this->setRawBits(value_ + 1);
    return old;
}

Fixed &Fixed::operator--() {
    this->value_ -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed old;
    old.value_ = this->value_;
    this->setRawBits(value_ - 1);
    return old;
}

//! MIN MAX

Fixed &Fixed::min(Fixed& left, Fixed& right) {
    if (left < right)
        return left;
    return right;
}

const Fixed &Fixed::min(const Fixed& left, const Fixed& right) {
    if (left.getRawBits() < right.getRawBits())
        return left;
    return right;
}

Fixed &Fixed::max(Fixed& left, Fixed& right) {
    if (left > right)
        return left;
    return right;
}

const Fixed &Fixed::max(const Fixed& left, const Fixed& right) {
    if (left.getRawBits() > right.getRawBits())
        return left;
    return right;
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