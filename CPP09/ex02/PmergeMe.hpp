/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:26:26 by paromero          #+#    #+#             */
/*   Updated: 2025/11/06 18:41:16 by paromero         ###   ########.fr       */
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
        void insertWithBinarySearch(std::deque<int>& container, int value);
    
    public:
        PmergeMe(int ac, char **av);
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe operator=(const PmergeMe &other);

        void    sort();
        const std::deque<int>& getContainer() const;
};

std::deque<std::pair<int, int> > mergeSortPairs(std::deque<std::pair<int, int> >& pairs);
std::deque<std::pair<int, int> > mergePairs(std::deque<std::pair<int, int> >& left, std::deque<std::pair<int, int> >& right);