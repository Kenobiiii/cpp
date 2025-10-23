/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:38:10 by paromero          #+#    #+#             */
/*   Updated: 2025/10/22 18:20:30 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() {
    this->Name_ = "Some generic AForm";
    this->isSigned_ = false;
    this->SignGrade_ = 150;
    this->ExecGrade_ = 150;
}

AForm::AForm(std::string name, bool isSigned, int signgrade, int execgrade) {
    if (signgrade < 1 || execgrade < 1)
        throw GradeTooHighException();
    if (signgrade > 150 || execgrade > 150)
        throw GradeTooLowException();
    this->Name_ = name;
    this->isSigned_ = isSigned;
    this->SignGrade_ = signgrade;
    this->ExecGrade_ = execgrade;
}

AForm::~AForm() {
}

AForm::AForm(const AForm& other) {
    this->Name_ = other.Name_;
    this->isSigned_ = other.isSigned_;
    this->SignGrade_ = other.SignGrade_;
    this->ExecGrade_ = other.ExecGrade_;
}

AForm& AForm::operator=(const AForm& other) {
       if (this == &other)
		return (*this);
	this->Name_ = other.Name_;
    this->isSigned_ = other.isSigned_;
    this->SignGrade_ = other.SignGrade_;
    this->ExecGrade_ = other.ExecGrade_;
	return (*this); 
}

std::string AForm::getName() const {
    return this->Name_;
}

int AForm::getSignGrade() const {
    return this->SignGrade_;
}

int AForm::getExecGrade() const {
    return this->ExecGrade_;
}

bool AForm::getIsSigned() const {
    return this->isSigned_;
}

void    AForm::beSigned(const Bureaucrat &B) {
    if (B.getGrade() > this->SignGrade_)
        throw GradeTooLowException();
    this->isSigned_ = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& other) {
    out << "AForm: " << other.getName() << ", SignGrade: " << other.getSignGrade() 
        << ", ExecGrade: " << other.getExecGrade() << ", Signed: " 
        << (other.getIsSigned() ? "yes" : "no") << std::endl;
    return out;
}