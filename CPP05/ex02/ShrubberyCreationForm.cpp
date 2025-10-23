/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:15:25 by paromero          #+#    #+#             */
/*   Updated: 2025/10/23 08:34:27 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
    
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137) {
    this->target_ = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137) {
    this->target_ = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", false, 145, 137) {
    this->target_ = other.target_;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (&other == this)
		return (*this);
	this->target_ = other.target_;
	return (*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw AForm::NotSigned();
    if (this->getExecGrade() < executor.getGrade())
        throw GradeTooLowException();
    std::ofstream outfile((this->target_ + "_shrubbery").c_str());
    outfile << "                 .o00o" << std::endl;
    outfile << "               o000000oo" << std::endl;
    outfile << "              00000000000o" << std::endl;
    outfile << "             00000000000000" << std::endl;
    outfile << "          oooooo  00000000  o88o" << std::endl;
    outfile << "       ooOOOOOOOoo  ```''  888888" << std::endl;
    outfile << "     OOOOOOOOOOOO'.qQQQQq. `8888'" << std::endl;
    outfile << "    oOOOOOOOOOO'.QQQQQQQQQQ/.88'" << std::endl;
    outfile << "    OOOOOOOOOO'.QQQQQQQQQQ/ /q" << std::endl;
    outfile << "     OOOOOOOOO QQQQQQQQQQ/ /QQ" << std::endl;
    outfile << "       OOOOOOOOO `QQQQQQ/ /QQ'" << std::endl;
    outfile << "         OO:F_P:O `QQQ/  /Q'" << std::endl;
    outfile << "            \\\\. \\ |  // |" << std::endl;
    outfile << "            d\\ \\\\\\|_// /" << std::endl;
    outfile << "            qP| \\\\ _' `|Ob" << std::endl;
    outfile << "               \\  / \\  \\Op" << std::endl;
    outfile << "               |  | O| |" << std::endl;
    outfile << "       _       /\\. \\_/ /\\" << std::endl;
    outfile << "        `---__/|_\\   //|  __" << std::endl;
    outfile << "              `-'  `-'`-'-'" << std::endl;
    outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}