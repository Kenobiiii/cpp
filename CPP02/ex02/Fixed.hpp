/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 08:47:47 by paromero          #+#    #+#             */
/*   Updated: 2025/10/14 10:49:22 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>
#include <cmath>

class Fixed {
    private:
        int value_;
        static const int FractionalBits_ = 8;

        public:
            Fixed();
            Fixed(const int value);
            Fixed(const float value);
            Fixed(const Fixed& other);
            ~Fixed();
            
            bool operator>(const Fixed& other) const;
            bool operator<(const Fixed& other) const;
            bool operator>=(const Fixed& other) const;
            bool operator<=(const Fixed& other) const;
            bool operator==(const Fixed& other) const;
            bool operator!=(const Fixed& other) const;
            
            Fixed& operator=(const Fixed& other);
            Fixed operator+(const Fixed& other) const;
            Fixed operator-(const Fixed& other) const;
            Fixed operator*(const Fixed& other) const;
            Fixed operator/(const Fixed& other) const;

            Fixed &operator++();
            Fixed operator++(int);
            Fixed &operator--();
            Fixed operator--(int);


            
            float toFloat(void) const;
            int toInt(void) const;
            int getRawBits(void) const;
            void setRawBits(int const raw);

            static Fixed &min(Fixed &left, Fixed &right);
            static const Fixed &min(const Fixed &left, const Fixed &right);
            static Fixed &max(Fixed &left, Fixed &right);
            static const Fixed &max(const Fixed &left, const Fixed &right);
        };

std::ostream& operator<<(std::ostream& out, const Fixed& other);