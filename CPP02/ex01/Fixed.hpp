/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:19:51 by paromero          #+#    #+#             */
/*   Updated: 2025/06/24 11:34:07 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cmath>

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
};

//- we need and especific function no manage de operator << with fixed vars
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);