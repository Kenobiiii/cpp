/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:22:50 by paromero          #+#    #+#             */
/*   Updated: 2025/06/06 12:43:25 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

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

#endif