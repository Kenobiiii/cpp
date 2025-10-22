/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:38:10 by paromero          #+#    #+#             */
/*   Updated: 2025/10/22 17:54:42 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() {
    this->Name_ = "Some generic form";
    this->isSigned_ = false;
    this->SignGrade_ = 150;
    this->ExecGrade_ = 150;
}

Form::Form(std::string name, bool isSigned, int signgrade, int execgrade) {
    if (signgrade < 1 || execgrade < 1)
        throw GradeTooHighException();
    if (signgrade > 150 || execgrade > 150)
        throw GradeTooLowException();
    this->Name_ = name;
    this->isSigned_ = isSigned;
    this->SignGrade_ = signgrade;
    this->ExecGrade_ = execgrade;
}

Form::~Form() {
}

Form::Form(const Form& other) {
    this->Name_ = other.Name_;
    this->isSigned_ = other.isSigned_;
    this->SignGrade_ = other.SignGrade_;
    this->ExecGrade_ = other.ExecGrade_;
}

Form& Form::operator=(const Form& other) {
       if (this == &other)
		return (*this);
	this->Name_ = other.Name_;
    this->isSigned_ = other.isSigned_;
    this->SignGrade_ = other.SignGrade_;
    this->ExecGrade_ = other.ExecGrade_;
	return (*this); 
}

std::string Form::getName() const {
    return this->Name_;
}

int Form::getSignGrade() const {
    return this->SignGrade_;
}

int Form::getExecGrade() const {
    return this->ExecGrade_;
}

bool Form::getIsSigned() const {
    return this->isSigned_;
}

void    Form::beSigned(const Bureaucrat &B) {
    if (B.getGrade() > this->SignGrade_)
        throw GradeTooLowException();
    this->isSigned_ = true;
}

std::ostream& operator<<(std::ostream& out, const Form& other) {
    out << "Form: " << other.getName() << ", SignGrade: " << other.getSignGrade() 
        << ", ExecGrade: " << other.getExecGrade() << ", Signed: " 
        << (other.getIsSigned() ? "yes" : "no") << std::endl;
    return out;
}