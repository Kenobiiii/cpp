/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:41:22 by paromero          #+#    #+#             */
/*   Updated: 2025/10/16 09:46:05 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n=== Creating DiamondTrap ===" << std::endl;
    DiamondTrap diamond("DIAMOND");
    
    std::cout << "\n=== Testing whoAmI ===" << std::endl;
    diamond.whoAmI();
    // Output: "I am DiamondTrap DIAMOND and my ClapTrap name is DIAMOND_clap_name"
    
    std::cout << "\n=== Testing inherited methods ===" << std::endl;
    diamond.attack("enemy");      // ScavTrap::attack() (20 damage)
    diamond.takeDamage(30);       // 100 HP - 30 = 70 HP
    diamond.beRepaired(20);       // 70 HP + 20 = 90 HP, consume 1 energy (50-1=49)
    
    std::cout << "\n=== Testing special abilities ===" << std::endl;
    diamond.guardGate();          // ScavTrap ability
    diamond.highFivesGuys();      // FragTrap ability
    
    std::cout << "\n=== End of test ===" << std::endl;
    return 0;
}
