/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:48:22 by paromero          #+#    #+#             */
/*   Updated: 2025/10/23 09:10:52 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <cctype>

Intern::Intern() {   
}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern::~Intern() {
}

Intern& Intern::operator=(const Intern& other) {
    if (this == &other)
        return (*this);
    (void)other;
    return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target) {
    std::string lowerFormName = "";
    for (size_t pos = 0; pos < formName.length(); pos++)
        lowerFormName += (char)std::tolower(formName[pos]);
    std::string formNames[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
    
    for (int i = 0; i < 3; i++) {
        if (lowerFormName == formNames[i]) {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            
            if (i == 0)
                return new RobotomyRequestForm(target);
            else if (i == 1)
                return new PresidentialPardonForm(target);
            else
                return new ShrubberyCreationForm(target);
        }
    }
    
    std::cout << "Intern cannot create " << formName << " form" << std::endl;
    return NULL;
}


