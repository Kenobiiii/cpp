/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:43:59 by paromero          #+#    #+#             */
/*   Updated: 2025/06/01 13:06:42 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

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

#endif

