/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:18:47 by paromero          #+#    #+#             */
/*   Updated: 2025/10/29 08:27:00 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void    printinmayus(const char &c) {
    std::cout << static_cast<char>(toupper(c)); 
}

int main() {
    char array[] = "Hello there!";
    ::iter(array, 13, printinmayus);
    std::cout << std::endl;

    return 0;
}