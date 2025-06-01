/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:44:03 by paromero          #+#    #+#             */
/*   Updated: 2025/06/01 13:06:42 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name_(name), weapon_(0) {
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon& weapon) {
    weapon_ = &weapon;
}

void HumanB::attack() const {
    if (weapon_) {
        std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
    } else {
        std::cout << name_ << " has no weapon to attack with!" << std::endl;
    }
}