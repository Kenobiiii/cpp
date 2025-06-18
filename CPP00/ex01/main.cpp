/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:22:30 by paromero          #+#    #+#             */
/*   Updated: 2025/06/17 15:09:30 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

int main() {
    PhoneBook phoneBook;
    std::string command;
    
    std::cout << "Welcome to your PhoneBook!" << std::endl;
    
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        }
        
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