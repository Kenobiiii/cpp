/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 09:29:19 by paromero          #+#    #+#             */
/*   Updated: 2025/06/01 10:07:44 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor - assigns name to the zombie
Zombie::Zombie(std::string name) : name_(name) {
}

// Destructor - prints message when zombie dies
Zombie::~Zombie() {
    std::cout << name_ << " is dead" << std::endl;
}

// Announce function - zombie announces itself
void Zombie::announce(void) {
    std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

