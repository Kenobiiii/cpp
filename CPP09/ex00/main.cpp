/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:40:34 by paromero          #+#    #+#             */
/*   Updated: 2025/11/04 11:57:39 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Use: ./btc name.txt" << std::endl;
        return 0;
    }
    std::string name = static_cast<std::string>(av[1]);
    
    // if (name.substr(name.length() - 4, 4) != ".csv") {
    //     std::cerr << "The file doesn't have the .csv extension" << std::endl;
    //     return 0;
    // }

    BitcoinExchange asd;

    asd.openinput(av[1]);
    //std::cout << "asd" << std::endl; 
    return 0;
}