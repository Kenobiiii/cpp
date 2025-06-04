/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:19:51 by paromero          #+#    #+#             */
/*   Updated: 2025/06/04 18:53:46 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed {
    private:
        int rawBits_;
        static const int fractionalBits_ = 8;
        
    public:
        Fixed();

        Fixed(const int value);
        
        Fixed(const float value);
        
        //- Copy constructor, copy into a new var the value and assigns new direction
        Fixed(const Fixed& other);
        
        //- Operator constructor, copy in an existing var the value and assigns new direction
        Fixed& operator=(const Fixed& other);
        
        ~Fixed();
        
        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        
        bool operator>(const Fixed& value) const;
        bool operator<(const Fixed& value) const;
        bool operator>=(const Fixed& value) const;
        bool operator<=(const Fixed& value) const;
        bool operator==(const Fixed& value) const;
        bool operator!=(const Fixed& value) const;
        
        Fixed operator+(const Fixed& value) const;
        Fixed operator-(const Fixed& value) const;
        Fixed operator*(const Fixed& value) const;
        Fixed operator/(const Fixed& value) const;
        
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        static Fixed min(Fixed& left, Fixed& right);
        static Fixed min(const Fixed& left, const Fixed& right);
        static Fixed max(Fixed& left, Fixed& right);
        static Fixed max(const Fixed& left, const Fixed& right);
};

//- we need especific functions to manage de operators with fixed vars
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif