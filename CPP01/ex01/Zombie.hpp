/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:22:05 by paromero          #+#    #+#             */
/*   Updated: 2025/06/24 11:25:43 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>
# include <sstream>

class Zombie {
    private:
        std::string name_;
    
    public:
        Zombie();
        Zombie(std::string name);
        
        ~Zombie();
        
        void announce(void);
        
        void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );