/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:40:00 by paromero          #+#    #+#             */
/*   Updated: 2025/06/02 12:45:27 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ParseFile.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "usage: ./search_and_replace filename s1 s2\n";
        return (1);
    }
    
    // Create object of ParseFile class
    ParseFile parser(av[1], av[2], av[3]);
    parser.processFile();
    return (0);
}