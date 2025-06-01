/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:16:53 by paromero          #+#    #+#             */
/*   Updated: 2025/06/01 12:35:09 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    
    // Print memory addresses by passing the direction
    std::cout << "Memory addresses:" << std::endl;
    std::cout << "str:       " << &str << std::endl;
    std::cout << "stringPTR: " << stringPTR << std::endl;
    std::cout << "stringREF: " << &stringREF << std::endl;
    
    // Print values
    std::cout << "\nValues:" << std::endl;
    std::cout << "str:       " << str << std::endl;
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;
    
    return 0;
}