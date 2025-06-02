/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:40:00 by paromero          #+#    #+#             */
/*   Updated: 2025/06/02 14:17:48 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

int main()
{
    Harl harl;
    
    std::cout << "=== Testing Harl complaints ===" << std::endl;
    
    harl.complain("DEBUG");
    
    harl.complain("INFO");
    
    harl.complain("WARNING");
    
    harl.complain("ERROR");
  
    return 0;
}