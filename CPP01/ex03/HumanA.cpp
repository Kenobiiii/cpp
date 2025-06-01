/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:43:40 by paromero          #+#    #+#             */
/*   Updated: 2025/06/01 13:06:42 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : name_(name), weapon_(weapon) {
}

HumanA::~HumanA() {
}

void HumanA::attack() const {
    std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}