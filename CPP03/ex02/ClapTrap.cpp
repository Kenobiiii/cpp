/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:41:52 by paromero          #+#    #+#             */
/*   Updated: 2025/10/15 16:47:35 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name) {
    std::cout << "ClapTrap Constructor called" << std::endl;
    this->Name_ = Name;
    this->HitPoints_ = 10;
    this->EnergyPoints_ = 10;
    this->AttackDamage_ = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy Constructor called for " << Name_ << std::endl;
    this->Name_ = other.Name_;
    this->HitPoints_ = other.HitPoints_;
    this->EnergyPoints_ = other.EnergyPoints_;
    this->AttackDamage_ = other.AttackDamage_;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->Name_ = other.Name_;
        this->HitPoints_ = other.HitPoints_;
        this->EnergyPoints_ = other.EnergyPoints_;
        this->AttackDamage_ = other.AttackDamage_;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called for " << Name_ << std::endl;
}

void    ClapTrap::attack(const std::string& target) {
    if (this->EnergyPoints_ <= 0 || this->HitPoints_ <= 0)
        std::cout << "ClapTrap " << this->Name_ << " don't has Energy Points in order to attack" << std::endl;
    else {
        std::cout << "ClapTrap " << this->Name_ << " attacks " << target << ", causing " << this->AttackDamage_ << " points of damage!" << std::endl;
        this->EnergyPoints_--;
    }
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (this->HitPoints_ <= 0)
        this->HitPoints_ -= amount;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (this->HitPoints_ <= 0)
        this->HitPoints_ += amount;
}