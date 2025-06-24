/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:22:50 by paromero          #+#    #+#             */
/*   Updated: 2025/06/24 11:31:17 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();

        ~Cat();

        //- Copy constructor, copy into a new var the value and assigns new direction
        Cat(const Cat& other);
        
        //- Operator constructor, copy in an existing var the value and assigns new direction
        Cat& operator=(const Cat& other);
        
        //- virtual means that the child class redefines the function
        void makeSound() const;

};
