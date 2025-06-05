/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:59:23 by paromero          #+#    #+#             */
/*   Updated: 2025/06/05 14:08:46 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include <cmath>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(const std::string& name);

        ~ScavTrap();

        //- Copy constructor, copy into a new var the value and assigns new direction
        ScavTrap(const ScavTrap& other);
        
        //- Operator constructor, copy in an existing var the value and assigns new direction
        ScavTrap& operator=(const ScavTrap& other);
        
        void attack(const std::string& target);
        void guardGate();

};

#endif