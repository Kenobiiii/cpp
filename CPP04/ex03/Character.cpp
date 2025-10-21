/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:15:31 by paromero          #+#    #+#             */
/*   Updated: 2025/10/21 10:17:09 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) {
    this->Name_ = name;
    this->count = 0;
    for (int i = 0; i < 4; i++)
        Materia_[i] = NULL;
    std::cout << "Character constructor called" << std::endl;
}

Character::Character(const Character& other) {
    this->Name_ = other.Name_;
    std::cout << "Character copy constructor called" << std::endl;
}

Character ::~Character() {
    for (int i = 0; i < 4; i++)
    {
        if (Materia_[i])
            delete Materia_[i];
    }
    std::cout << "Character destructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
    if (this == &other)
		return (*this);
	this->Name_ = other.Name_;
	return (*this);
}

std::string const &Character::getName() const {
    return Name_;
}

void    Character::equip(AMateria* m) {
    if (count < 4)
    {
        Materia_[count] = m;
        count++;
    }
}

void    Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !Materia_[idx])
        return;
    Materia_[idx] = NULL;   
    for (int i = idx; i < 3; i++)
        Materia_[i] = Materia_[i + 1];
    Materia_[3] = NULL;
    count--;
}

void    Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !Materia_[idx])
        return;
    Materia_[idx]->use(target);
}