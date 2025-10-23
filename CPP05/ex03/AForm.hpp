/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:20:23 by paromero          #+#    #+#             */
/*   Updated: 2025/10/23 09:07:09 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include <fstream>
#include <iostream>
#include <cctype>

class Bureaucrat;

class AForm {
    private:
        std::string Name_;
        bool        isSigned_;
        int         SignGrade_;
        int         ExecGrade_;

    public:
        AForm();
        AForm(std::string name, bool isSigned, int signgrade, int execgrade);
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        std::string getName() const;
        int         getSignGrade() const;
        int         getExecGrade() const;
        bool        getIsSigned() const;
        
        void        beSigned(const Bureaucrat &B);
        virtual void execute(Bureaucrat const & executor) const = 0;

        class NotSigned : public std::exception { 
        public:
            const char * what () const throw ()  { 
                return ("The form is not signed"); 
            } 
};
        
};

std::ostream& operator<<(std::ostream& out, const AForm& other);