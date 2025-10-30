/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:10:10 by paromero          #+#    #+#             */
/*   Updated: 2025/10/30 08:49:58 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    // Prueba con vector
    std::vector<int>::iterator itVec = easyfind(vec, 20);
    if (itVec != vec.end())
        std::cout << "Encontrado en vector: " << *itVec << std::endl;
    else
        std::cout << "No encontrado en vector." << std::endl;

    // Prueba con list
    std::list<int>::iterator itList = easyfind(lst, 99);
    if (itList != lst.end())
        std::cout << "Encontrado en lista: " << *itList << std::endl;
    else
        std::cout << "No encontrado en lista." << std::endl;

    return 0;
}