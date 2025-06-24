/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:43:33 by paromero          #+#    #+#             */
/*   Updated: 2025/06/24 11:25:43 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Weapon.hpp"
# include <iostream>

class HumanA {
    private:
        std::string name_;
        Weapon& weapon_;
        
    public:
        HumanA(const std::string& name, Weapon& weapon);
        ~HumanA();
        
        void attack() const;
};

