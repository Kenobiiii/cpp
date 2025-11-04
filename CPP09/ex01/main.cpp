/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:15:09 by paromero          #+#    #+#             */
/*   Updated: 2025/11/04 20:20:46 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    try {
        RPN rpn(av[1]);
        std::cout << rpn.getResult() << std::endl;
    }
    catch (...) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}