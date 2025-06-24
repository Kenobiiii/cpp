/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:42:09 by paromero          #+#    #+#             */
/*   Updated: 2025/06/24 11:25:43 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>
# include <sstream>

class Weapon {
    private:
        std::string type_;
        
    public:
    Weapon();
    Weapon(const std::string& type);
    ~Weapon();

    const std::string& getType() const;
    
    void setType(const std::string& type);
};