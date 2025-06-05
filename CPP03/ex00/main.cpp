/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:20:30 by paromero          #+#    #+#             */
/*   Updated: 2025/06/04 19:25:24 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	// Crear un ClapTrap
	ClapTrap robot("R2D2");

	// Probar ataque
	robot.attack("enemigo");

	// Probar daño
	std::cout << "\n--- El robot recibe daño ---" << std::endl;
	robot.takeDamage(3);

	// Probar reparación
	std::cout << "\n--- El robot se repara ---" << std::endl;
	robot.beRepaired(2);

	// Probar muerte
	std::cout << "\n--- El robot recibe daño crítico ---" << std::endl;
	robot.takeDamage(10);

	// Probar acciones después de muerto
	std::cout << "\n--- Intentar acciones después de morir ---" << std::endl;
	robot.attack("enemigo");
	robot.beRepaired(5);
	robot.takeDamage(2);

	// Probar constructor copia
	std::cout << "\n--- Probar constructor de copia ---" << std::endl;
	ClapTrap robot2 = robot;
	robot2.takeDamage(1);

	// Probar asignación
	std::cout << "\n--- Probar operador de asignación ---" << std::endl;
	ClapTrap robot3("C3PO");
	robot3 = robot;
	robot3.beRepaired(1);

	std::cout << "\n--- Fin del programa ---" << std::endl;
	return 0;
}
