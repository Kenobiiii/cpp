/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:21:49 by paromero          #+#    #+#             */
/*   Updated: 2025/06/01 10:39:48 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    std::cout << "Creating a horde of 5 zombies..." << std::endl;
    
    // Create horde of 5 zombies in heap
    Zombie* horde = zombieHorde(5, "HordeZombie");
    
    std::cout << "\nMaking each zombie announce itself:" << std::endl;
    // Make each zombie announce itself
    for (int i = 0; i < 5; i++) {
        std::cout << "Zombie " << i + 1 << ": ";
        horde[i].announce();
    }
    
    std::cout << "\nDeleting the horde..." << std::endl;
    // Free memory from array (use delete[], not delete)
    delete[] horde;
    
    return 0;
}

