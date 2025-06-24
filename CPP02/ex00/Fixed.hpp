/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:19:51 by paromero          #+#    #+#             */
/*   Updated: 2025/06/24 11:25:43 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

class Fixed {
    private:
        int rawBits_;
        static const int fractionalBits_ = 8;
        
    public:
        Fixed();
        
        //- Copy constructor, copy into a new var the value and assigns new direction
        Fixed(const Fixed& other);
        
        //- Operator constructor, copy in an existing var the value and assigns new direction
        //- to manage custom operator implementation the sytax is class& operator(and de op you want to add, like this case "=")
        Fixed& operator=(const Fixed& other);
        
        ~Fixed();
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
};