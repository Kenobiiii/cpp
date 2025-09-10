/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:21:49 by paromero          #+#    #+#             */
/*   Updated: 2025/09/10 10:21:45 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    std::cout << "Creating a horde of 5 zombies...\n" << std::endl;
    
    Zombie* horde = zombieHorde(5, "HordeZombie");
    
    std::cout << "Making each zombie announce itself:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }
    
    std::cout << "\nDeleting the horde..." << std::endl;
    delete[] horde;
    
    return 0;
}

