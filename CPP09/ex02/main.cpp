/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:48:44 by paromero          #+#    #+#             */
/*   Updated: 2025/11/06 18:48:47 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    try {
        // Mostrar ANTES
        std::cout << "Before: ";
        for (int i = 1; i < ac; i++) {
            std::cout << av[i];
            if (i < ac - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
        
        // ========== CON DEQUE ==========
        PmergeMe pmergeDeque(ac, av);
        
        clock_t startDeque = clock();
        pmergeDeque.sort();
        clock_t endDeque = clock();
        
        double elapsedDeque = double(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000.0;
        
        // Mostrar DESPUÉS
        std::cout << "==================================After==================================" << std::endl;
        const std::deque<int>& result = pmergeDeque.getContainer();
        for (size_t i = 0; i < result.size(); i++) {
            std::cout << result[i];
            if (i < result.size() - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
        
        // Mostrar tiempo
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << (ac - 1) 
                  << " elements with std::deque : " << elapsedDeque << " us" << std::endl;
        
    } catch (const std::exception &e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}
