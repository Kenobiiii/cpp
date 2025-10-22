/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:04:36 by paromero          #+#    #+#             */
/*   Updated: 2025/10/22 13:06:21 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "GradeTooLowException.hpp"
#include "GradeTooHighException.hpp"

int main() {
    // Test 1: Crear un burocrata válido
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 2: Crear un burocrata con grado muy alto (inválido)
    try {
        Bureaucrat alice("Alice", 0);
        std::cout << alice << std::endl;
    } catch (const GradeTooHighException& e) {
        std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    }

    // Test 3: Crear un burocrata con grado muy bajo (inválido)
    try {
        Bureaucrat charlie("Charlie", 151);
        std::cout << charlie << std::endl;
    } catch (const GradeTooLowException& e) {
        std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    }

    // Test 4: Incrementar grado sin alcanzar el límite
    try {
        Bureaucrat david("David", 50);
        std::cout << "Before increment: " << david << std::endl;
        david.incrementGrade();
        std::cout << "After increment: " << david << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 5: Intentar incrementar cuando ya está en el máximo (grado 1)
    try {
        Bureaucrat eve("Eve", 1);
        std::cout << "Before increment: " << eve << std::endl;
        eve.incrementGrade();  // Esto debe lanzar excepción
        std::cout << "After increment: " << eve << std::endl;
    } catch (const GradeTooHighException& e) {
        std::cout << "Caught GradeTooHighException: " << e.what() << std::endl;
    }

    // Test 6: Decrementar grado sin alcanzar el límite
    try {
        Bureaucrat frank("Frank", 100);
        std::cout << "Before decrement: " << frank << std::endl;
        frank.decrementGrade();
        std::cout << "After decrement: " << frank << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 7: Intentar decrementar cuando ya está en el mínimo (grado 150)
    try {
        Bureaucrat grace("Grace", 150);
        std::cout << "Before decrement: " << grace << std::endl;
        grace.decrementGrade();  // Esto debe lanzar excepción
        std::cout << "After decrement: " << grace << std::endl;
    } catch (const GradeTooLowException& e) {
        std::cout << "Caught GradeTooLowException: " << e.what() << std::endl;
    }

    return 0;
}