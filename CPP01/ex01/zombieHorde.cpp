/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:22:19 by paromero          #+#    #+#             */
/*   Updated: 2025/06/01 10:39:48 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    // Create array of N zombies in heap (single allocation)
    Zombie* horde = new Zombie[N];
    
    // Assign the same name to all zombies
    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }
    
    // Return pointer to the first zombie
    return horde;
}