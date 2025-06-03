/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:19:51 by paromero          #+#    #+#             */
/*   Updated: 2025/06/03 12:23:24 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {
    private:
        int rawBits_;
        static const int fractionalBits_ = 8;
        
    public:
        // 1. Constructor por defecto
        Fixed();
        
        //- Copy constructor, copy into a new var the value and assigns new direction
        Fixed(const Fixed& other);
        
        //- Operator constructor, copy in an existing var the value and assigns new direction
        Fixed& operator=(const Fixed& other);
        
        ~Fixed();
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif