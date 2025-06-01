/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 09:28:13 by paromero          #+#    #+#             */
/*   Updated: 2025/06/01 10:10:41 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    std::cout << "Testing stack zombies (randomChump):" << std::endl;
    randomChump("StackZombie1");
    
    std::cout << "\nTesting heap zombies (newZombie):" << std::endl;
    Zombie* heapZombie1 = newZombie("HeapZombie1");
    
    heapZombie1->announce();
    
    delete heapZombie1;
    
    return 0;
}

