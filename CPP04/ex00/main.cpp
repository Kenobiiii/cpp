/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:43:31 by paromero          #+#    #+#             */
/*   Updated: 2025/10/16 13:24:20 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal("Animal");
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	i->MakeSound(); //will output the cat sound!
	j->MakeSound();
	meta->MakeSound();
	
	delete meta;
	delete j;
	delete i;
	
	std::cout << "\n--- Testing WrongAnimal ---" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	wrongCat->makeSound();
	wrongMeta->makeSound();
	
	delete wrongMeta;
	delete wrongCat;

	return 0;
}
