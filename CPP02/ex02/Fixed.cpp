/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:25:04 by paromero          #+#    #+#             */
/*   Updated: 2025/06/04 18:55:25 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : rawBits_(0) {
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : rawBits_(other.rawBits_) {
    //std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->rawBits_ = other.rawBits_;
    }
    return *this;
}

Fixed::~Fixed() {
    //std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->rawBits_;
}

void Fixed::setRawBits(int const raw) {
    this->rawBits_ = raw;
}

// Constructor con entero
Fixed::Fixed(const int value) {
    //std::cout << "Int constructor called" << std::endl;
    this->rawBits_ = value << fractionalBits_;  // Desplazar bits para fixed-point
}

// Constructor con float
Fixed::Fixed(const float value) {
    //std::cout << "Float constructor called" << std::endl;
    this->rawBits_ = roundf(value * (1 << fractionalBits_));  // Convertir y redondear
}

// Convertir fixed-point a float
float Fixed::toFloat() const {
    return (float)this->rawBits_ / (1 << fractionalBits_);
}

// Convertir fixed-point a int
int Fixed::toInt() const {
    return this->rawBits_ >> fractionalBits_;  // Desplazar bits para obtener parte entera
}

// Operador de inserción (<<)
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();  // Insertar representación en punto flotante
    return out;
}

bool Fixed::operator>(const Fixed& value) const {
    return getRawBits() > value.getRawBits();
}

bool Fixed::operator<(const Fixed& value) const {
    return getRawBits() < value.getRawBits();
}

bool Fixed::operator>=(const Fixed& value) const {
    return getRawBits() >= value.getRawBits();
}

bool Fixed::operator<=(const Fixed& value) const {
    return getRawBits() <= value.getRawBits();
}

bool Fixed::operator==(const Fixed& value) const {
    return getRawBits() == value.getRawBits();
}

bool Fixed::operator!=(const Fixed& value) const {
    return getRawBits() != value.getRawBits();
}

Fixed Fixed::operator+(const Fixed& value) const {
    return getRawBits() + value.getRawBits();
}

Fixed Fixed::operator-(const Fixed& value) const {
    return getRawBits() - value.getRawBits();
}

Fixed Fixed::operator*(const Fixed& value) const {
    return toFloat() * value.toFloat();
}

Fixed Fixed::operator/(const Fixed& value) const {
    return toFloat() / value.toFloat();
}

Fixed &Fixed::operator++() {
    rawBits_ += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed old;
    old.rawBits_ = rawBits_;
    setRawBits(rawBits_ + 1);
    return (old);
}

Fixed &Fixed::operator--() {
    rawBits_ -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed old;
    old.rawBits_ = rawBits_;
    setRawBits(rawBits_ - 1);
    return (old);
}

Fixed Fixed::min(Fixed& left, Fixed& right) {
    if (left < right)
        return left;
    return right;
}

Fixed Fixed::min(const Fixed& left, const Fixed& right) {
    if (left < right)
        return left;
    return right;
}

Fixed Fixed::max(Fixed& left, Fixed& right) {
    if (left > right)
        return left;
    return right;
}

Fixed Fixed::max(const Fixed& left, const Fixed& right) {
    if (left > right)
        return left;
    return right;
}