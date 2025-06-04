/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:25:04 by paromero          #+#    #+#             */
/*   Updated: 2025/06/04 19:41:33 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <cmath>

class ClapTrap {
    private:
        string name_;
        const int Hit_points__ = 10;
        const int Energy_points_ = 10;
        const int Attack_damage_ = 0;
        
    public:
        ClapTrap();

        ~ClapTrap();
        
        ClapTrap(const int value);
        
        ClapTrap(const float value);
        
        //- Copy constructor, copy into a new var the value and assigns new direction
        ClapTrap(const ClapTrap& other);
        
        //- Operator constructor, copy in an existing var the value and assigns new direction
        ClapTrap& operator=(const ClapTrap& other);
        
        
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif