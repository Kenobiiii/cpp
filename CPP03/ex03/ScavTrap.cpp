/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:41:00 by paromero          #+#    #+#             */
/*   Updated: 2025/10/16 09:54:20 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "ScavTrap Constructor called" << std::endl;
    this->HitPoints_ = 100;
    this->EnergyPoints_ = 50;
    this->AttackDamage_ = 20;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << Name_ << std::endl;
}

void    ScavTrap::attack(const std::string& target) {
    if (this->EnergyPoints_ <= 0 || this->HitPoints_ <= 0)
        std::cout << "ScavTrap " << this->Name_ << " don't has Energy Points in order to attack" << std::endl;
    else {
        std::cout << "ScavTrap " << this->Name_ << " attacks " << target << ", causing " << this->AttackDamage_ << " points of damage!" << std::endl;
        this->EnergyPoints_--;
    }
}
    
void ScavTrap::guardGate() {
    if (this->HitPoints_ > 0)
        std::cout << "ScavTrap " << this->Name_ << " is now in Gate Keeper mode" << std::endl;
}
