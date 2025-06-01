/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:22:23 by paromero          #+#    #+#             */
/*   Updated: 2025/06/01 10:39:48 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Default constructor
Zombie::Zombie() : name_("") {
}

// Constructor that receives the name
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

// Setter to assign name
void Zombie::setName(std::string name) {
    name_ = name;
}

