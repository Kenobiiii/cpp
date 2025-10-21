/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 09:42:17 by paromero          #+#    #+#             */
/*   Updated: 2025/10/21 10:17:09 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    count = 0;
    for (int i = 0; i < 4; i++)
        Materia_[i] = NULL;
    std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    this->count = other.count;
    for (int i = 0; i < 4; i++)
        this->Materia_[i] = other.Materia_[i];
    std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
    {
        if (Materia_[i])
            delete Materia_[i];
    }
    std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this == &other)
        return (*this);
    this->count = other.count;
    for (int i = 0; i < 4; i++)
        this->Materia_[i] = other.Materia_[i];
    return (*this);
}

void    MateriaSource::learnMateria(AMateria* Materia) {
    if (count < 4) {
        this->Materia_[count] = Materia;
        count++;
    }
}

AMateria*    MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++)
	{
		if (Materia_[i] && Materia_[i]->getType() == type)
			return Materia_[i]->clone();
	}
	return (NULL);
}