/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:28:22 by paromero          #+#    #+#             */
/*   Updated: 2025/11/06 12:42:22 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) {
    for (int i = 1; i < ac; ++i) {
        std::stringstream ss(av[i]);
        int num;
        if (!(ss >> num) || num < 0) {
            throw std::runtime_error("Error");
        }
        this->dequecont_.push_back(num);
    }
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &other) {
    this->dequecont_ = other.dequecont_;
}

PmergeMe    PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other)
        this->dequecont_ = other.dequecont_;
    return *this;
}

void    PmergeMe::sort() {
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> main;
    std::deque<int> pend;
    int straggler = -1;

    for (size_t i = 0; i < this->dequecont_.size() - 1; i += 2) {
        int num1 = this->dequecont_[i];
        int num2 = this->dequecont_[i + 1];
        if (num1 < num2)
            pairs.push_back(std::make_pair(num1, num2));
        else
            pairs.push_back(std::make_pair(num2, num1));
    }

    if (this->dequecont_.size() % 2 != 0)
        straggler = this->dequecont_[this->dequecont_.size() - 1];
    

    for (size_t j = 0; j < pairs.size(); j++) {
        main.push_back(pairs[j].second);
        pend.push_back(pairs[j].first);
    }
}

std::deque<std::pair<int, int>> mergeSortPairs(std::deque<std::pair<int, int>>& pairs) {
    if (pairs.size() <= 1)
        return pairs;
    
    size_t mid = pairs.size() / 2;
    std::deque<std::pair<int, int>> left(pairs.begin(), pairs.begin() + mid);
    std::deque<std::pair<int, int>> right(pairs.begin() + mid, pairs.end());
    
    left = mergeSortPairs(left);
    right = mergeSortPairs(right);
    
    return mergePairs(left, right);
}

std::deque<std::pair<int, int>> mergePairs(std::deque<std::pair<int, int>>& left, std::deque<std::pair<int, int>>& right) {
    std::deque<std::pair<int, int>> result;
    size_t i = 0, j = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i].second <= right[j].second)
            result.push_back(left[i++]);
        else
            result.push_back(right[j++]);
    }
    
    while (i < left.size())
        result.push_back(left[i++]);
    while (j < right.size())
        result.push_back(right[j++]);
    
    return result;
}