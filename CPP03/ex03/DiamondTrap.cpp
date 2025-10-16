/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:15:53 by paromero          #+#    #+#             */
/*   Updated: 2025/10/16 09:47:26 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), Name_(name) {
    this->HitPoints_ = 100;
    this->EnergyPoints_ = 50;
    this->AttackDamage_ = 30;
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called for " << Name_ << std::endl;
}

void    DiamondTrap::whoAmI() {
    std::cout << "I am a DiamondTrap named: " << this->Name_ << ", ClapTrap name: " << ClapTrap::Name_ << std::endl;
}

