/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:14:17 by paromero          #+#    #+#             */
/*   Updated: 2025/10/21 10:06:15 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
    this->type = type;
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
    this->type = other.type;
    std::cout << "AMateria copy constructor called" << std::endl;
}


AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        type = other.type;
        std::cout << "AMateria assignment operator called" << std::endl;
    }
    return *this;
}

std::string const & AMateria::getType() const {
    return type;
}

void        AMateria::use(ICharacter& target) {
    std::cout << "AMateria " << type << " used on " << target.getName() << std::endl;
}