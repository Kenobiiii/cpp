/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:26:26 by paromero          #+#    #+#             */
/*   Updated: 2025/11/11 17:20:54 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <list>
#include <iostream>
#include <climits>
#include <sstream>
#include <algorithm>
#include <utility>

std::deque<int> sortWithDeque(int ac, char **av);
std::list<int> sortWithList(int ac, char **av);