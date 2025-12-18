/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:40:34 by paromero          #+#    #+#             */
/*   Updated: 2025/12/18 13:05:48 by paromero         ###   ########.fr       */
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
    BitcoinExchange asd;

    asd.openinput(av[1]);
    asd.printResults();
    
    return 0;
}