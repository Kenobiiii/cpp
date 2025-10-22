/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:28:49 by paromero          #+#    #+#             */
/*   Updated: 2025/10/22 17:22:11 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    Name_ = "Rookie";
    Grade_ = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->Name_ = name;
    this->Grade_ = grade;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    this->Name_ = other.Name_;
    this->Grade_ = other.Grade_;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this == &other)
		return (*this);
	this->Name_ = other.Name_;
    this->Grade_ = other.Grade_;
	return (*this);
}

std::string Bureaucrat::getName() const {
    return this->Name_;
}

int Bureaucrat::getGrade() const {
    return this->Grade_;
}

void    Bureaucrat::incrementGrade() {
    if (this->Grade_ <= 1)
        throw GradeTooHighException();
    else
        this->Grade_--;
}

void    Bureaucrat::decrementGrade() {
    if (this->Grade_ >= 150)
        throw GradeTooLowException();
    else
        this->Grade_++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other) {
    out << other.getName() << ", Bureaucrat grade " << other.getGrade() << std::endl;
    return out;
}
