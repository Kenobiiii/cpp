/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:41:09 by paromero          #+#    #+#             */
/*   Updated: 2025/10/15 16:53:07 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(const std::string& name);
        ~ScavTrap();
        
        void attack(const std::string& target);
        void guardGate();
};