/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:25:04 by paromero          #+#    #+#             */
/*   Updated: 2025/06/24 11:29:31 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <iostream>
# include <string>
# include <cmath>

class ClapTrap {
    protected:
        std::string name_;
        int Hit_points_;
        int Energy_points_;
        int Attack_damage_;
        
    public:
        ClapTrap(const std::string& name);

        ~ClapTrap();

        //- Copy constructor, copy into a new var the value and assigns new direction
        ClapTrap(const ClapTrap& other);
        
        //- Operator constructor, copy in an existing var the value and assigns new direction
        ClapTrap& operator=(const ClapTrap& other);
        
        
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};