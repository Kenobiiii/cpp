/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:42:15 by paromero          #+#    #+#             */
/*   Updated: 2025/06/01 13:06:42 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){
}

Weapon::Weapon(const std::string& type) : type_(type) {
}

Weapon::~Weapon(){
}

void Weapon::setType(const std::string& type) {
    type_ = type;
}

const std::string& Weapon::getType() const {
    return type_;
}