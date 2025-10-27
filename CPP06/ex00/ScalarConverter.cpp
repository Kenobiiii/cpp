/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:05:41 by paromero          #+#    #+#             */
/*   Updated: 2025/10/27 10:52:03 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void) other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void) other;
    return *this;
}

bool    ScalarConverter::isOnlyChar(const std::string &input) {
    if (input.length() != 3)
        return false;
    if (input[0] != '\'' || input[2] != '\'')
        return false;
    if (!isprint(static_cast<unsigned char>(input[1])))
        return false;
    return true;
}

bool    ScalarConverter::isChar(const std::string &input) {
    if (input.length() != 1)
        return false;
    if (!isprint(static_cast<unsigned char>(input[0])))
        return false;
    return true;
}

bool    ScalarConverter::ispseudo(const std::string &input) {
    if (input == "nanf" || input == "+inff" || input == "-inff")
        return true;

    if (input == "nan" || input == "+inf" || input == "-inf")
        return true;
    return false;
}

bool    ScalarConverter::isInt(const std::string &input) {
    size_t start = 0;
    if (input[0] == '+' || input[0] == '-')
        start = 1;
    if (start == input.size())
        return false;

    for (size_t i = start; i < input.size(); ++i) {
        if (!isdigit(static_cast<unsigned char>(input[i])))
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string &input) {
    size_t start = 0;
    if (input[0] == '+' || input[0] == '-')
        start = 1;
    if (start >= input.size())
        return false;

    if (input[input.size() - 1] != 'f')
        return false;
    
    int dotCount = 0;
    for (size_t i = start; i < input.size() - 1; ++i) {
        if (input[i] == '.') {
            ++dotCount;
            if (dotCount > 1) return false;
        }
        else if (!isdigit(static_cast<unsigned char>(input[i]))) {
            return false;
        }
    }

    return dotCount == 1;
}

bool ScalarConverter::isDouble(const std::string &input) {
    size_t start = 0;
    if (input[0] == '+' || input[0] == '-')
        start = 1;
    if (start >= input.size())
        return false;

    int dotCount = 0;
    for (size_t i = start; i < input.size(); ++i) {
        if (input[i] == '.') {
            ++dotCount;
            if (dotCount > 1) return false;
        }
        else if (!isdigit(static_cast<unsigned char>(input[i]))) {
            return false;
        }
    }

    return dotCount == 1;
}

void ScalarConverter::convert(const std::string &input) {
    if (input.empty()) {
        std::cout << "Input is empty, please add anything" << std::endl;
        return;
    }

    else if (ispseudo(input)) {
        if (input == "nanf" || input == "+inff" || input == "-inff") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << input << std::endl;
            std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
        }
        if (input == "nan" || input == "+inf" || input == "-inf") {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << input << "f" << std::endl;
            std::cout << "double: " << input << std::endl;
        }
        
        return;
    }

    else if (isOnlyChar(input)) {
        char c = input[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    else if (isChar(input)) {
        char c = input[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        return;
    }

    else if (isInt(input)) {
        int n = atoi(input.c_str());
        if (n < 0 || n > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!isprint(static_cast<unsigned char>(n)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
        std::cout << "int: " << n << std::endl;
        std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
        return;
    }

    else if (isFloat(input)) {
        float f = atof(input.c_str());
        if (f < 0 || f > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!isprint(static_cast<unsigned char>(f)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

        if (f > static_cast<float>(std::numeric_limits<int>::max()) ||
            f < static_cast<float>(std::numeric_limits<int>::min()))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;

        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
        return;
    }

    else if (isDouble(input)) {
        double d = atof(input.c_str());
        if (d < 0 || d > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!isprint(static_cast<unsigned char>(d)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

        if (d > static_cast<double>(std::numeric_limits<int>::max()) ||
            d < static_cast<double>(std::numeric_limits<int>::min()))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;

        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

