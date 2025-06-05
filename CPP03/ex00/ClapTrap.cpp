/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:25:11 by paromero          #+#    #+#             */
/*   Updated: 2025/06/04 19:25:36 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name_(name) {
    Hit_points_ = 10;
    Energy_points_ = 10;
    Attack_damage_ = 0;
	std::cout << "ClapTrap default constructor called for " << name_ << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : 
    name_(other.name_), 
    Hit_points_(other.Hit_points_),
    Energy_points_(other.Energy_points_), 
    Attack_damage_(other.Attack_damage_) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other) {  // Protección contra auto-asignación
        name_ = other.name_;
        Hit_points_ = other.Hit_points_;
        Energy_points_ = other.Energy_points_;
        Attack_damage_ = other.Attack_damage_;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << name_ << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (Hit_points_ <= 0) {
		std::cout << "ClapTrap" << name_ << "is dead and can't attack!" << std::endl;
		return;
	}
	if (Energy_points_ <= 0) {
    	std::cout << "ClapTrap " << name_ << " has no energy to attack!" << std::endl;
    	return;
    }

    Energy_points_--;
    std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing " << Attack_damage_ << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (Hit_points_ <= 0) {
        std::cout << "ClapTrap " << name_ << " is already dead!" << std::endl;
        return;
    }

    Hit_points_ -= amount;
    if (Hit_points_ < 0) {
        Hit_points_ = 0;
    }

    std::cout << "ClapTrap " << name_ << " takes " << amount
              << " points of damage! Hit points: " << Hit_points_ << std::endl;

    if (Hit_points_ == 0) {
        std::cout << "ClapTrap " << name_ << " has died!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (Hit_points_ <= 0) {
        std::cout << "ClapTrap " << name_ << " is dead and can't be repaired!" << std::endl;
        return;
    }
    if (Energy_points_ <= 0) {
        std::cout << "ClapTrap " << name_ << " has no energy to repair!" << std::endl;
        return;
    }

    Energy_points_--;
    Hit_points_ += amount;

    std::cout << "ClapTrap " << name_ << " repairs itself for " << amount
              << " hit points! Current hit points: " << Hit_points_ << std::endl;
}
