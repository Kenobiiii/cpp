/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:40:55 by paromero          #+#    #+#             */
/*   Updated: 2025/10/20 17:41:24 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"

class Cure : public AMateria {

    public:
        Cure();
        virtual ~Cure();
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);

        AMateria* clone() const;
        void use(ICharacter& target);
};
