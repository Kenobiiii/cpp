/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:19:07 by paromero          #+#    #+#             */
/*   Updated: 2025/10/18 13:38:53 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal {
    private:
        Brain *brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        
        void MakeSound() const;
};