/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 08:47:47 by paromero          #+#    #+#             */
/*   Updated: 2025/10/14 09:05:47 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>

class Fixed {
    private:
        int value_;
        static const int FractionalBits_ = 8;

        public:
            Fixed();
            Fixed(const Fixed& other);
            Fixed& operator=(const Fixed& other);
            ~Fixed();

            int getRawBits(void) const;
            void setRawBits(int const raw);
};