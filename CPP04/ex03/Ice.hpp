/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:07:02 by paromero          #+#    #+#             */
/*   Updated: 2025/10/21 10:01:54 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Ice : public AMateria {

    public:
        Ice();
        virtual ~Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);

        AMateria* clone() const;
        void use(ICharacter& target);
};
