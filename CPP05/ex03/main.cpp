/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:04:36 by paromero          #+#    #+#             */
/*   Updated: 2025/10/23 09:02:29 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main() {
    std::cout << "\n========== INTERN TESTS ==========" << std::endl;

    // Test 1: Intern creates robotomy request form
    try {
        std::cout << "\n[Test 1] Intern creates RobotomyRequestForm:" << std::endl;
        Intern intern;
        AForm *form = intern.makeForm("robotomy request", "Bender");
        
        Bureaucrat boss("Boss", 1);
        boss.signForm(*form);
        boss.executeForm(*form);
        
        delete form;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 2: Intern creates shrubbery creation form
    try {
        std::cout << "\n[Test 2] Intern creates ShrubberyCreationForm:" << std::endl;
        Intern intern;
        AForm *form = intern.makeForm("shrubbery creation", "garden");
        
        Bureaucrat boss("Boss", 1);
        boss.signForm(*form);
        boss.executeForm(*form);
        
        delete form;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 3: Intern creates presidential pardon form
    try {
        std::cout << "\n[Test 3] Intern creates PresidentialPardonForm:" << std::endl;
        Intern intern;
        AForm *form = intern.makeForm("presidential pardon", "Criminal");
        
        Bureaucrat boss("Boss", 1);
        boss.signForm(*form);
        boss.executeForm(*form);
        
        delete form;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 4: Invalid form name
    try {
        std::cout << "\n[Test 4] Invalid form name:" << std::endl;
        Intern intern;
        AForm *form = intern.makeForm("invalid form", "target");
        
        if (form)
            delete form;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 5: Case insensitive test
    try {
        std::cout << "\n[Test 5] Case insensitive - ROBOTOMY REQUEST:" << std::endl;
        Intern intern;
        AForm *form = intern.makeForm("ROBOTOMY REQUEST", "R2D2");
        
        Bureaucrat boss("Boss", 1);
        boss.signForm(*form);
        boss.executeForm(*form);
        
        delete form;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 6: Intern with different bureaucrat grades
    try {
        std::cout << "\n[Test 6] Intern form with low-grade bureaucrat:" << std::endl;
        Intern intern;
        AForm *form = intern.makeForm("presidential pardon", "Innocent");
        
        Bureaucrat lowGrade("Lowbie", 150);
        lowGrade.signForm(*form);
        lowGrade.executeForm(*form);
        
        delete form;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}