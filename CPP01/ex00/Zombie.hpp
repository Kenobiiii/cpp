/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 09:28:52 by paromero          #+#    #+#             */
/*   Updated: 2025/06/24 11:26:52 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <iomanip>
# include <sstream>

class Zombie {
    private:
        std::string name_;
    
    public:
        // Constructor que recibe el nombre
        Zombie(std::string name);
        
        // Destructor
        ~Zombie();
        
        // Función que hace que el zombie se anuncie
        void announce(void);
};

// Declaraciones de las funciones globales
Zombie* newZombie(std::string name);
void randomChump(std::string name);