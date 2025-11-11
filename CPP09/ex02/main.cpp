/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:48:44 by paromero          #+#    #+#             */
/*   Updated: 2025/11/11 17:21:16 by paromero         ###   ########.fr       */
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
        std::cout << "Before: ";
        for (int i = 1; i < ac; i++) {
            std::cout << av[i];
            if (i < ac - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
        
        clock_t startDeque = clock();
        std::deque<int> resultDeque = sortWithDeque(ac, av);
        clock_t endDeque = clock();
        
        clock_t startList = clock();
        std::list<int> resultList = sortWithList(ac, av);
        clock_t endList = clock();
        
        double elapsedDeque = double(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000.0;
        double elapsedList = double(endList - startList) / CLOCKS_PER_SEC * 1000000.0;
        
        std::cout << "After: ";
        for (std::deque<int>::iterator it = resultDeque.begin(); it != resultDeque.end(); ++it) {
            if (it != resultDeque.begin())
                std::cout << " ";
            std::cout << *it;
        }
        std::cout << std::endl;
        
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Time to process a range of " << (ac - 1) 
                  << " elements with std::deque : " << elapsedDeque << " us" << std::endl;
        std::cout << "Time to process a range of " << (ac - 1) 
                  << " elements with std::list : " << elapsedList << " us" << std::endl;
        
    } catch (const std::exception &e) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}