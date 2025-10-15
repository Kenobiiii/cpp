/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:41:22 by paromero          #+#    #+#             */
/*   Updated: 2025/10/15 17:22:12 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main () {
	std::cout << "=== Testing ClapTrap ===" << std::endl;
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

	std::cout << "\n=== Testing ScavTrap ===" << std::endl;
	// Crear un ScavTrap - mostrará la cadena de construcción
	ScavTrap scavenger("ST-01");

	// Probar ataque de ScavTrap (mensaje diferente)
	scavenger.attack("target");

	// Probar habilidad especial
	scavenger.guardGate();

	// Probar herencia de métodos de ClapTrap
	std::cout << "\n--- Testing inherited methods ---" << std::endl;
	scavenger.takeDamage(30);
	scavenger.beRepaired(15);

	// Probar constructor de copia de ScavTrap
	std::cout << "\n--- Testing ScavTrap copy constructor ---" << std::endl;
	ScavTrap scavenger2(scavenger);
	scavenger2.attack("another target");
	scavenger2.guardGate();

	// Probar operador de asignación
	std::cout << "\n--- Testing ScavTrap assignment operator ---" << std::endl;
	ScavTrap scavenger3("ST-03");
	scavenger3 = scavenger;
	scavenger3.guardGate();

	// Probar que ScavTrap tiene los valores correctos inicializados
	std::cout << "\n--- Testing ScavTrap initial values ---" << std::endl;
	ScavTrap testScav("TEST");
	// ScavTrap should have 100 HP, 50 Energy, 20 Attack damage
	for (int i = 0; i < 25; i++) { // Test that it can attack more than ClapTrap
		testScav.attack("dummy");
	}

	std::cout << "\n--- End of tests - Destruction will occur in reverse order ---" << std::endl;
	return 0;
}