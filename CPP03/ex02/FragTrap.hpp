/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:15:00 by paromero          #+#    #+#             */
/*   Updated: 2025/06/24 11:34:07 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(const std::string& name);

        ~FragTrap();

        //- Copy constructor, copy into a new var the value and assigns new direction
        FragTrap(const FragTrap& other);
        
        //- Operator constructor, copy in an existing var the value and assigns new direction
        FragTrap& operator=(const FragTrap& other);
        
        void highFivesGuys(void);

};