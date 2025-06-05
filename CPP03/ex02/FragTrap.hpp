/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:15:00 by paromero          #+#    #+#             */
/*   Updated: 2025/06/05 14:15:41 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include <cmath>
# include "ClapTrap.hpp"

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

#endif
