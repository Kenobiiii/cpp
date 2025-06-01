/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 10:22:05 by paromero          #+#    #+#             */
/*   Updated: 2025/06/01 10:40:07 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

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

#endif