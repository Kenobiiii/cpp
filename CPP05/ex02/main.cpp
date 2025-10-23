/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:04:36 by paromero          #+#    #+#             */
/*   Updated: 2025/10/23 08:44:00 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "GradeTooLowException.hpp"
#include "GradeTooHighException.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    std::cout << "\n========== SHRUBBERY CREATION FORM TESTS ==========" << std::endl;
    
    // Test 1: Successful execution (sign 145, exec 137)
    try {
        std::cout << "\n[Test 1] Successful execution:" << std::endl;
        Bureaucrat b1("Boss", 130);
        ShrubberyCreationForm form1("home");
        b1.signForm(form1);
        b1.executeForm(form1);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 2: Grade too low to sign
    try {
        std::cout << "\n[Test 2] Grade too low to sign (needs 145):" << std::endl;
        Bureaucrat b2("Junior", 146);
        ShrubberyCreationForm form2("office");
        b2.signForm(form2);
        b2.executeForm(form2);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 3: Grade too low to execute
    try {
        std::cout << "\n[Test 3] Grade too low to execute (needs 137):" << std::endl;
        Bureaucrat b3("SignerOnly", 144);
        ShrubberyCreationForm form3("garden");
        b3.signForm(form3);
        b3.executeForm(form3);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 4: Form not signed
    try {
        std::cout << "\n[Test 4] Form not signed:" << std::endl;
        Bureaucrat b4("Executor", 130);
        ShrubberyCreationForm form4("park");
        b4.executeForm(form4);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n========== ROBOTOMY REQUEST FORM TESTS ==========" << std::endl;
    
    // Test 5: Successful execution (sign 72, exec 45)
    try {
        std::cout << "\n[Test 5] Successful execution:" << std::endl;
        Bureaucrat b5("Chief", 5);
        RobotomyRequestForm form5("Marvin");
        b5.signForm(form5);
        b5.executeForm(form5);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 6: Grade too low to sign
    try {
        std::cout << "\n[Test 6] Grade too low to sign (needs 72):" << std::endl;
        Bureaucrat b6("Intern", 73);
        RobotomyRequestForm form6("Robot");
        b6.signForm(form6);
        b6.executeForm(form6);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 7: Grade too low to execute
    try {
        std::cout << "\n[Test 7] Grade too low to execute (needs 45):" << std::endl;
        Bureaucrat b7("SignerOnly", 70);
        RobotomyRequestForm form7("Android");
        b7.signForm(form7);
        b7.executeForm(form7);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 8: Form not signed
    try {
        std::cout << "\n[Test 8] Form not signed:" << std::endl;
        Bureaucrat b8("Executor", 40);
        RobotomyRequestForm form8("Cyborg");
        b8.executeForm(form8);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n========== PRESIDENTIAL PARDON FORM TESTS ==========" << std::endl;
    
    // Test 9: Successful execution (sign 25, exec 5)
    try {
        std::cout << "\n[Test 9] Successful execution:" << std::endl;
        Bureaucrat b9("President", 1);
        PresidentialPardonForm form9("Criminal");
        b9.signForm(form9);
        b9.executeForm(form9);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 10: Grade too low to sign
    try {
        std::cout << "\n[Test 10] Grade too low to sign (needs 25):" << std::endl;
        Bureaucrat b10("VicePresident", 26);
        PresidentialPardonForm form10("Prisoner");
        b10.signForm(form10);
        b10.executeForm(form10);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 11: Grade too low to execute
    try {
        std::cout << "\n[Test 11] Grade too low to execute (needs 5):" << std::endl;
        Bureaucrat b11("SignerOnly", 24);
        PresidentialPardonForm form11("Suspect");
        b11.signForm(form11);
        b11.executeForm(form11);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 12: Form not signed
    try {
        std::cout << "\n[Test 12] Form not signed:" << std::endl;
        Bureaucrat b12("Executor", 1);
        PresidentialPardonForm form12("Innocent");
        b12.executeForm(form12);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}