/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:20:30 by paromero          #+#    #+#             */
/*   Updated: 2025/06/06 12:05:46 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	std::cout << "=== Testing ClapTrap ===" << std::endl;
	ClapTrap robot("R2D2");

	robot.attack("enemigo");

	std::cout << "\n--- El robot recibe daño ---" << std::endl;
	robot.takeDamage(3);

	std::cout << "\n--- El robot se repara ---" << std::endl;
	robot.beRepaired(2);

	std::cout << "\n=== Testing ScavTrap ===" << std::endl;
	ScavTrap scavenger("ST-01");

	scavenger.attack("target");

	scavenger.guardGate();

	std::cout << "\n--- Testing inherited methods ---" << std::endl;
	scavenger.takeDamage(30);
	scavenger.beRepaired(15);

	std::cout << "\n--- Testing ScavTrap copy constructor ---" << std::endl;
	ScavTrap scavenger2(scavenger);
	scavenger2.attack("another target");
	scavenger2.guardGate();

	std::cout << "\n--- Testing ScavTrap assignment operator ---" << std::endl;
	ScavTrap scavenger3("ST-03");
	scavenger3 = scavenger;
	scavenger3.guardGate();

	std::cout << "\n--- Testing ScavTrap initial values ---" << std::endl;
	ScavTrap testScav("TEST");

	for (int i = 0; i < 25; i++) {
		testScav.attack("dummy");
	}

	std::cout << "\n=== Testing FragTrap ===" << std::endl;
	FragTrap fragger("FT-01");

	fragger.highFivesGuys();

	std::cout << "\n--- Testing FragTrap inherited methods ---" << std::endl;
	fragger.attack("enemy");
	fragger.takeDamage(40);
	fragger.beRepaired(20);

	std::cout << "\n--- Testing FragTrap copy constructor ---" << std::endl;
	FragTrap fragger2(fragger);
	fragger2.highFivesGuys();
	fragger2.attack("target");

	std::cout << "\n--- Testing FragTrap assignment operator ---" << std::endl;
	FragTrap fragger3("FT-03");
	fragger3 = fragger;
	fragger3.highFivesGuys();

	std::cout << "\n--- Testing FragTrap initial values ---" << std::endl;
	FragTrap testFrag("FRAGTEST");
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
