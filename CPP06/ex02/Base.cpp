/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:13:49 by paromero          #+#    #+#             */
/*   Updated: 2025/10/28 09:36:56 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base    *generate(void) {
    srand(time(0));
    int random  = rand() % 3;
    
    switch (random)
    {
    case 0:
        return new A;
        break;
    
    case 1:
        return new B;
        break;

    case 2:
        return new C;
        break;
    default:
        return new A;
    }  
}

void    identify(Base* p) {
    std::string type = "";
    if (dynamic_cast<A*>(p))
        type = "A";
    else if (dynamic_cast<B*>(p))
        type = "B";
    else
        type = "C";
    std::cout << "el puntero es de tipo: " << type << std::endl;
}

void	identify(Base &p)
{
	std::string type = "";
	try
	{
		dynamic_cast<A&>(p);
		type = "A";
	}
	catch (...) {}
	try
	{
		dynamic_cast<B&>(p);
		type = "B";
	}
	catch (...) {}
	try
	{
		dynamic_cast<C&>(p);
		type = "C";
	}
	catch (...) {}
	std::cout << "La referencia es de tipo " << type << std::endl;
}

