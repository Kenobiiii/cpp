/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:05:33 by paromero          #+#    #+#             */
/*   Updated: 2025/10/28 08:13:59 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

class ScalarConverter {
    public:
        static void convert(const std::string &input);
    
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        static bool    ispseudo(const std::string &input);
        static bool    isOnlyChar(const std::string &input);
        static bool    isChar(const std::string &input);
        static bool    isInt(const std::string &input);
        static bool    isFloat(const std::string &input);
        static bool    isDouble(const std::string &input);
};