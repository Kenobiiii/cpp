/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:24:34 by paromero          #+#    #+#             */
/*   Updated: 2025/10/22 17:54:54 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class Bureaucrat;

class Form {
    private:
        std::string Name_;
        bool        isSigned_;
        int         SignGrade_;
        int         ExecGrade_;

    public:
        Form();
        Form(std::string name, bool isSigned, int signgrade, int execgrade);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

        std::string getName() const;
        int         getSignGrade() const;
        int         getExecGrade() const;
        bool        getIsSigned() const;
        
        void        beSigned(const Bureaucrat &B);
        
};

std::ostream& operator<<(std::ostream& out, const Form& other);