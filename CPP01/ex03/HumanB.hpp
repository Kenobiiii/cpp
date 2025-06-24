/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:43:59 by paromero          #+#    #+#             */
/*   Updated: 2025/06/24 11:25:43 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Weapon.hpp"
# include <iostream>

class HumanB {
    private:
        std::string name_;
        Weapon* weapon_;
        
    public:
        HumanB(const std::string& name);
        ~HumanB();
        
        void setWeapon(Weapon& weapon);
        void attack() const;
};

