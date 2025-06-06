/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:02:23 by paromero          #+#    #+#             */
/*   Updated: 2025/06/06 12:43:25 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <cmath>

class Animal {
    protected:
        std::string type_;
        
    public:
        Animal(const std::string& type = "Animal");

        virtual ~Animal();

        //- Copy constructor, copy into a new var the value and assigns new direction
        Animal(const Animal& other);
        
        //- Operator constructor, copy in an existing var the value and assigns new direction
        Animal& operator=(const Animal& other);
        
    //- virtual means that the child class redefines the function
    virtual void makeSound() const;
    std::string getType() const;
};

#endif