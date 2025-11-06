/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:28:22 by paromero          #+#    #+#             */
/*   Updated: 2025/11/06 09:54:08 by paromero         ###   ########.fr       */
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

std::deque<int> mergeSort(std::deque<int>& cont) {
    if (cont.size() <= 1)
        return cont;
    
    size_t mid = cont.size() / 2;
    std::deque<int> left(cont.begin(), cont.begin() + mid);
    std::deque<int> right(cont.begin() + mid, cont.end());
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    return merge(left, right);
}

std::deque<int> merge(std::deque<int>& left, std::deque<int>& right) {
    std::deque<int> result;
    size_t i = 0, j = 0;
    
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j])
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