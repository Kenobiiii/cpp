/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:22:30 by paromero          #+#    #+#             */
/*   Updated: 2025/06/18 17:30:13 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

std::string ft_toupper(std::string& str) {
    for (size_t i = 0; i < str.length(); i++)
        str[i] = (char)std::toupper(str[i]);
    return str;
}

int main(int ac, char **av) {
    PhoneBook phoneBook;
    std::string command;
    (void)av;
    
    if (ac != 1) {
        std::cout << "Use: PhoneBook\n";
        return 0;
    }
    
    std::cout << "Welcome to your PhoneBook!" << std::endl;
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        }
        command = ft_toupper(command);
        if (command == "ADD") {
            phoneBook.addContact();
        }
        else if (command == "SEARCH") {
            phoneBook.searchContact();
        }
        else if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else {
            std::cout << "Invalid command. Use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    
    return 0;
}