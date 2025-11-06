/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:26:26 by paromero          #+#    #+#             */
/*   Updated: 2025/11/06 09:50:29 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <deque>
#include <iostream>
#include <climits>
#include <sstream>
#include <algorithm>
#include <utility>

class PmergeMe {
    private:
        std::deque<int> dequecont_;
    
    public:
        PmergeMe(int ac, char **av);
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe operator=(const PmergeMe &other);

        void    sort();
};

std::deque<int> mergeSort(std::deque<int>& cont);
std::deque<int> merge(std::deque<int>& left, std::deque<int>& right);