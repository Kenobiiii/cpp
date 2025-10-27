/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:38:45 by paromero          #+#    #+#             */
/*   Updated: 2025/10/27 10:39:03 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main() {
    std::string tests[] = {
        "nan", "+inf", "-inf", "nanf", "+inff", "-inff",
        "'a'", "b",
        "42", "-100",
        "4.2f", "-0.5f",
        "3.14", "-2.718",
        "hello"
    };

    for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i) {
        std::cout << "=== Test input: " << tests[i] << " ===" << std::endl;
        ScalarConverter::convert(tests[i]);
        std::cout << std::endl;
    }

    return 0;
}
