/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:40:34 by paromero          #+#    #+#             */
/*   Updated: 2025/11/04 17:35:30 by paromero         ###   ########.fr       */
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
    
    if (name.substr(name.length() - 4, 4) != ".txt") {
        std::cerr << "The file doesn't have the .txt extension" << std::endl;
        return 0;
    }

    BitcoinExchange asd;

    asd.openinput(av[1]);
    asd.printResults();
    
    return 0;
}