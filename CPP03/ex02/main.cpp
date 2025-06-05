/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:20:30 by paromero          #+#    #+#             */
/*   Updated: 2025/06/05 14:08:46 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
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

	std::cout << "\n=== Testing FragTrap ===" << std::endl;
	// Crear un FragTrap - mostrará la cadena de construcción
	FragTrap fragger("FT-01");

	// Probar habilidad especial
	fragger.highFivesGuys();

	// Probar herencia de métodos de ClapTrap
	std::cout << "\n--- Testing FragTrap inherited methods ---" << std::endl;
	fragger.attack("enemy");
	fragger.takeDamage(40);
	fragger.beRepaired(20);

	// Probar constructor de copia de FragTrap
	std::cout << "\n--- Testing FragTrap copy constructor ---" << std::endl;
	FragTrap fragger2(fragger);
	fragger2.highFivesGuys();
	fragger2.attack("target");

	// Probar operador de asignación
	std::cout << "\n--- Testing FragTrap assignment operator ---" << std::endl;
	FragTrap fragger3("FT-03");
	fragger3 = fragger;
	fragger3.highFivesGuys();

	// Probar que FragTrap tiene los valores correctos inicializados
	std::cout << "\n--- Testing FragTrap initial values ---" << std::endl;
	FragTrap testFrag("FRAGTEST");
	// FragTrap should have 100 HP, 100 Energy, 30 Attack damage
	std::cout << "FragTrap can attack many times with 100 energy points:" << std::endl;
	for (int i = 0; i < 5; i++) { // Show some attacks with high damage
		testFrag.attack("training dummy");
	}

	std::cout << "\n--- Comparison of all three classes ---" << std::endl;
	ClapTrap clap("CLAP");
	ScavTrap scav("SCAV");
	FragTrap frag("FRAG");
	
	std::cout << "\nAttacking with different classes:" << std::endl;
	clap.attack("target");    // 0 damage
	scav.attack("target");    // 20 damage
	frag.attack("target");    // 30 damage
	
	std::cout << "\nSpecial abilities:" << std::endl;
	scav.guardGate();
	frag.highFivesGuys();

	std::cout << "\n--- End of tests - Destruction will occur in reverse order ---" << std::endl;
	return 0;
}
