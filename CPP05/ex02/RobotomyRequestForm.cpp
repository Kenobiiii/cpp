/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:07:37 by paromero          #+#    #+#             */
/*   Updated: 2025/10/23 08:43:11 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45) {
    this->target_ = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45) {
    this->target_ = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", false, 72, 45) {
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
        throw AForm::NotSigned();
    if (this->getExecGrade() < executor.getGrade())
        throw GradeTooLowException();
    srand(time(0));
    int random  = rand() % 2;

    if (random % 2 == 0)
        std::cout << this->target_ << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomization failed for " << this->target_ << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}