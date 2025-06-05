/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:59:02 by paromero          #+#    #+#             */
/*   Updated: 2025/06/05 14:08:46 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    Hit_points_ = 100;
    Energy_points_ = 50;
    Attack_damage_ = 20;
    std::cout << "ScavTrap constructor called for " << name_ << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called for " << name_ << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (Hit_points_ <= 0) {
        std::cout << "ScavTrap " << name_ << " is dead and can't attack!" << std::endl;
        return;
    }
    if (Energy_points_ <= 0) {
        std::cout << "ScavTrap " << name_ << " has no energy to attack!" << std::endl;
        return;
    }

    Energy_points_--;
    std::cout << "ScavTrap " << name_ << " attacks " << target << ", causing " << Attack_damage_ << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode!" << std::endl;
}

