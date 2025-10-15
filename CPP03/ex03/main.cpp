/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:41:22 by paromero          #+#    #+#             */
/*   Updated: 2025/10/15 17:42:54 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main () {
	std::cout << "\n=== Testing FragTrap ===" << std::endl;
	FragTrap fragger("FT-01");

	fragger.highFivesGuys();

	std::cout << "\n--- Testing FragTrap inherited methods ---" << std::endl;
	fragger.attack("enemy");
	fragger.takeDamage(40);
	fragger.beRepaired(20);

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