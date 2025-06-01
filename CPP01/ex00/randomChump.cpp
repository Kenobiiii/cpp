/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 09:29:34 by paromero          #+#    #+#             */
/*   Updated: 2025/06/01 10:07:44 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Creates zombie on STACK - announces and dies when function ends
void randomChump(std::string name) {
    Zombie zombie(name);
    zombie.announce();
}

