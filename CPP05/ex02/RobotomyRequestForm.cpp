/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:07:37 by paromero          #+#    #+#             */
/*   Updated: 2025/10/23 08:14:55 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
    this->target_ = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
    this->target_ = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72, 45) {
    this->target_ = other.target_;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (&other == this)
		return (*this);
	this->target_ = other.target_;
	return (*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw NotSigned();
    if (this->getExecGrade() < executor.getGrade())
        throw GradeTooLowException();
    srand(time(0));
    int random  = rand() % 2;

    if (random % 2 == 0)
        std::cout << this->target_ << " has been robotomized" << std::endl;
    else
        std::cout << "The robotomization failed in " << this->target_ << std::endl;
}