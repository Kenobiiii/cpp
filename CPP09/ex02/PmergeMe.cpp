/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paromero <paromero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 20:28:22 by paromero          #+#    #+#             */
/*   Updated: 2025/12/18 09:56:57 by paromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void insertWithBinarySearchDeque(std::deque<int>& container, int value) {
    std::deque<int>::iterator it = std::lower_bound(container.begin(), container.end(), value);
    container.insert(it, value);
}

static std::deque<std::pair<int, int> > mergePairsDeque(std::deque<std::pair<int, int> >& left, std::deque<std::pair<int, int> >& right) {
    std::deque<std::pair<int, int> > result;
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

static std::deque<std::pair<int, int> > mergeSortPairsDeque(std::deque<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1)
        return pairs;
    
    size_t mid = pairs.size() / 2;
    std::deque<std::pair<int, int> > left(pairs.begin(), pairs.begin() + mid);
    std::deque<std::pair<int, int> > right(pairs.begin() + mid, pairs.end());
    
    left = mergeSortPairsDeque(left);
    right = mergeSortPairsDeque(right);
    
    return mergePairsDeque(left, right);
}

static std::deque<size_t> generateJacbosthalDeque(size_t n) {
    std::deque<size_t> jacob;
    jacob.push_back(1);
    jacob.push_back(3);
    //! first two values of jacobsthal

    while (jacob.back() < n) {
        size_t last = jacob.back();
        size_t prev = jacob[jacob.size() - 2]; //! we access the penultimate
        jacob.push_back(last + (2 * prev)); //! formula: Jn = Jn-1 (last) + 2 * Jn-2 (penultimate)
    }
    return jacob;
}

std::deque<int> sortWithDeque(int ac, char **av) {
    std::deque<int> input;
    
    for (int i = 1; i < ac; ++i) {
        std::stringstream ss(av[i]);
        int num;
        if (!(ss >> num) || num < 0) {
            throw std::runtime_error("Error");
        }
        input.push_back(num);
    }
    
    if (input.size() <= 1)
        return input;
    
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> main;
    std::deque<int> pend;
    int straggler = -1;

    for (size_t i = 0; i < input.size() - 1; i += 2) {
        int num1 = input[i];
        int num2 = input[i + 1];
        if (num1 < num2)
            pairs.push_back(std::make_pair(num1, num2));
        else
            pairs.push_back(std::make_pair(num2, num1));
    }

    if (input.size() % 2 != 0)
        straggler = input[input.size() - 1];
    
    pairs = mergeSortPairsDeque(pairs);
        
    for (size_t j = 0; j < pairs.size(); j++) {
        main.push_back(pairs[j].second);
        pend.push_back(pairs[j].first);
    }

    std::deque<int> result;
    result.push_back(pend[0]);

    for (size_t i = 0; i < main.size(); i++)
        result.push_back(main[i]);
    

    std::deque<size_t> jacobsq = generateJacbosthalDeque(pend.size());  //! generate the value in base of the size of pend
    size_t last_pos = 1; //! we inserted one value, so last_pos = 1
    for (size_t i = 0; i < jacobsq.size(); i++) {
        size_t current_jacob = jacobsq[i];
        size_t limit = current_jacob;
        if (limit > pend.size())
            limit = pend.size();
        for (size_t j = limit; j > last_pos; j--)
            insertWithBinarySearchDeque(result, pend[j - 1]);
        
        last_pos = limit;
    }
    
    if (straggler != -1) {
        insertWithBinarySearchDeque(result, straggler);
    }
    
    return result;
}

static void insertWithBinarySearchList(std::list<int>& container, int value) {
    std::list<int>::iterator it = std::lower_bound(container.begin(), container.end(), value);
    container.insert(it, value);
}

static std::list<std::pair<int, int> > mergePairsList(std::list<std::pair<int, int> >& left, std::list<std::pair<int, int> >& right) {
    std::list<std::pair<int, int> > result;
    std::list<std::pair<int, int> >::iterator i = left.begin();
    std::list<std::pair<int, int> >::iterator j = right.begin();
    
    while (i != left.end() && j != right.end()) {
        if (i->second <= j->second) {
            result.push_back(*i);
            ++i;
        } else {
            result.push_back(*j);
            ++j;
        }
    }
    
    while (i != left.end()) {
        result.push_back(*i);
        ++i;
    }
    while (j != right.end()) {
        result.push_back(*j);
        ++j;
    }
    
    return result;
}

static std::list<std::pair<int, int> > mergeSortPairsList(std::list<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1)
        return pairs;
    
    size_t mid = pairs.size() / 2;
    std::list<std::pair<int, int> > left;
    std::list<std::pair<int, int> > right;
    
    std::list<std::pair<int, int> >::iterator it = pairs.begin();
    for (size_t i = 0; i < mid; ++i) {
        left.push_back(*it);
        ++it;
    }
    while (it != pairs.end()) {
        right.push_back(*it);
        ++it;
    }
    
    left = mergeSortPairsList(left);
    right = mergeSortPairsList(right);
    
    return mergePairsList(left, right);
}

//! Como list no tiene operador [], se crea esta función
static int getElementAt(std::list<int>& lst, size_t index) {
    std::list<int>::iterator it = lst.begin();
    std::advance(it, index);
    return *it;
}

static std::list<size_t> generateJacbosthalList(size_t n) {
    std::list<size_t> jacob;
    jacob.push_back(1);
    jacob.push_back(3);

    while (true) {
        size_t last = jacob.back();
        std::list<size_t>::iterator it = jacob.end();
        it--;
        it--;
        size_t prev = *it;

        size_t next = last + (2 * prev);
        if (next >= n && last >= n)
            break;
        jacob.push_back(next);
        if (next >= n)
            break;
    }
    return jacob;
}

std::list<int> sortWithList(int ac, char **av) {
    std::list<int> input;
    
    for (int i = 1; i < ac; ++i) {
        std::stringstream ss(av[i]);
        int num;
        if (!(ss >> num) || num < 0) {
            throw std::runtime_error("Error");
        }
        input.push_back(num);
    }
    
    if (input.size() <= 1)
        return input;
    
    std::list<std::pair<int, int> > pairs;
    std::list<int> main;
    std::list<int> pend;
    int straggler = -1;

    std::list<int>::iterator it = input.begin();
    while (it != input.end()) {
        int num1 = *it;
        ++it;
        if (it == input.end()) {
            straggler = num1;
            break;
        }
        int num2 = *it;
        ++it;
        
        if (num1 < num2)
            pairs.push_back(std::make_pair(num1, num2));
        else
            pairs.push_back(std::make_pair(num2, num1));
    }
    
    pairs = mergeSortPairsList(pairs);
        
    for (std::list<std::pair<int, int> >::iterator iter = pairs.begin(); iter != pairs.end(); ++iter) {
        main.push_back(iter->second);
        pend.push_back(iter->first);
    }

    std::list<int> result;
    result.push_back(pend.front());

    for (std::list<int>::iterator iter = main.begin(); iter != main.end(); ++iter)
        result.push_back(*iter);
    
    std::list<size_t> jacobsq = generateJacbosthalList(pend.size());
    size_t last_pos = 1;
    for (std::list<size_t>::iterator iter = jacobsq.begin(); iter != jacobsq.end(); ++iter) {
        size_t current_jacob = *iter;
        size_t limit = current_jacob;
        
        if (limit > pend.size())
            limit = pend.size();
        
        for (size_t j = limit; j > last_pos; j--) {
            int val = getElementAt(pend, j - 1);
            insertWithBinarySearchList(result, val);
        }
        last_pos = limit;
    }
    
    if (straggler != -1) {
        insertWithBinarySearchList(result, straggler);
    }
    
    return result;
}