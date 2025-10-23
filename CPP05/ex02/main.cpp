/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:04:36 by paromero          #+#    #+#             */
/*   Updated: 2025/10/23 08:28:28 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "GradeTooLowException.hpp"
#include "GradeTooHighException.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    std::cout << std::endl << "===== TESTS FOR FORM =====" << std::endl << std::endl;

    // Test 8: Crear un formulario válido
    try {
        Form f1("Tax Form", false, 50, 25);
        std::cout << f1 << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 9: Firmar un formulario con un burocrata de grado suficiente
    try {
        Bureaucrat alice("Alice", 40);
        Form taxForm("Tax Form", false, 50, 25);
        std::cout << "Before signing: " << taxForm;
        alice.signForm(taxForm);
        std::cout << "After signing: " << taxForm;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 10: Intentar firmar un formulario sin tener grado suficiente
    try {
        Bureaucrat junior("Junior", 100);
        Form taxForm("Tax Form", false, 50, 25);
        std::cout << "Before signing: " << taxForm;
        junior.signForm(taxForm);
        std::cout << "After signing: " << taxForm;
    } catch (const GradeTooLowException& e) {
        std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    }

    // Test 11: Crear un formulario con grado de firma inválido
    try {
        Form invalidForm("Invalid Form", false, 0, 25);
        std::cout << invalidForm << std::endl;
    } catch (const GradeTooHighException& e) {
        std::cout << "Caught GradeTooHighException during form creation: " << e.what() << std::endl;
    }

    // Test 12: Crear un formulario con grado de ejecución inválido
    try {
        Form invalidForm("Invalid Form", false, 50, 151);
        std::cout << invalidForm << std::endl;
    } catch (const GradeTooLowException& e) {
        std::cout << "Caught GradeTooLowException during form creation: " << e.what() << std::endl;
    }

    return 0;
}