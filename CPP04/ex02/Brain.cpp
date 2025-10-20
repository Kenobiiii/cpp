/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:43:20 by paromero          #+#    #+#             */
/*   Updated: 2025/10/18 13:45:12 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    *this = other;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain&    Brain::operator=(const Brain& other) {
	if (this == &other)
		return (*this);
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	return (*this);
}

std::string Brain::getIdea(int i) const {
    return ideas[i];
}

void    Brain::setIdea(int i, std::string idea) {
    ideas[i] = idea;
}