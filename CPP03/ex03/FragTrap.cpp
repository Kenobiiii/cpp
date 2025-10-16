/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:35:21 by paromero          #+#    #+#             */
/*   Updated: 2025/10/16 09:54:00 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    std::cout << "FragTrap Constructor called" << std::endl;
    this->HitPoints_ = 100;
    this->EnergyPoints_ = 100;
    this->AttackDamage_ = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << Name_ << std::endl;
}

void    FragTrap::attack(const std::string& target) {
    if (this->EnergyPoints_ <= 0 || this->HitPoints_ <= 0)
        std::cout << "FragTrap " << this->Name_ << " don't has Energy Points in order to attack" << std::endl;
    else {
        std::cout << "FragTrap " << this->Name_ << " attacks " << target << ", causing " << this->AttackDamage_ << " points of damage!" << std::endl;
        this->EnergyPoints_--;
    }
}

void FragTrap::highFivesGuys(void) {
    if (this->HitPoints_ > 0)
        std::cout << "FragTrap " << this->Name_ << " wants a high-five" << std::endl;    
}